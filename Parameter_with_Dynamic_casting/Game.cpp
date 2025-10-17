#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Card type and helpers
struct Card {
    int rank; // 1=A, 2..10, 11=J, 12=Q, 13=K
    char suit;  // 'S','H','D','C'
};

string rankName(int r) {
    if (r == 1) return "A";
    if (r >= 2 && r <= 10) return to_string(r);
    if (r == 11) return "J";
    if (r == 12) return "Q";
    return "K";
}

string suitName(char s) {
    switch (s) {
        case 'S': return "S"; case 'H': return "H";
        case 'D': return "D"; default: return "C";
    }
}

string cardToString(const Card &c) {
    return rankName(c.rank) + suitName(c.suit);
}

// Deck creation & shuffle
vector<Card> createDeck() {
    vector<Card> deck;
    char suits[4] = {'S', 'H', 'D', 'C'};
    for (char s : suits)
        for (int r = 1; r <= 13; r++)
            deck.push_back(Card{r, s});
    return deck;
}

void shuffleDeck(vector<Card> &deck) {
    static mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    shuffle(deck.begin(), deck.end(), rng);
}

// Deal a card
Card deal(vector<Card> &deck) {
    if (deck.empty()) {
        deck = createDeck();
        shuffleDeck(deck);
    }
    Card c = deck.back();
    deck.pop_back();
    return c;
}

// Represent hands & compute value (Ace logic)
int handValue(const vector<Card> &hand) {
    int total = 0, aces = 0;
    for (auto &c : hand) {
        if (c.rank == 1) { aces++; total += 11; }
        else if (c.rank >= 11) total += 10;
        else total += c.rank;
    }
    while (total > 21 && aces > 0) { total -= 10; --aces; }
    return total;
}

bool isBlackjack(const vector<Card> &hand) {
    return (hand.size() == 2 && handValue(hand) == 21);
}

// Print hands (with dealer hidden card)
void printHand(const vector<Card> &hand, bool hideFirst=false) {
    if (hideFirst && !hand.empty()) {
        cout << "[??] ";
        for (size_t i = 1; i < hand.size(); i++) cout << "[" << cardToString(hand[i]) << "] ";
    } else {
        for (auto &c : hand) cout << "[" << cardToString(c) << "] ";
    }
}

// Dealer rules
void dealerPlay(vector<Card> &dealer, vector<Card> &deck) {
    while (handValue(dealer) < 17) {
        dealer.push_back(deal(deck));
    }
}

// Bets & bankroll handling
double promptBet(double bankroll) {
    while (true) {
        cout << "Bet (bankroll $" << bankroll << "): ";
        string s; if (!getline(cin, s)) return 0;
        try { double b = stod(s); if (b>0 && b<=bankroll) return b; }
        catch (...) {}
        cout << "Invalid bet\n";
    }
}

// Prompt player action
char promptAction(bool canDouble) {
    while (true) {
        cout << "Choose action: (h)it, (s)tand" << (canDouble ? ", (d)ouble" : "") << ": ";
        string s; if (!getline(cin, s)) return 's';
        if (s.empty()) continue;
        char a = tolower(s[0]);
        if (a == 'h' || a == 's' || (a == 'd' && canDouble)) return a;
        cout << "Invalid action.\n";
    }
}

// Main game loop
int main() {
    auto deck = createDeck();
    shuffleDeck(deck);
    double bankroll = 100.0;

    while (bankroll > 0.0) {
        double bet = promptBet(bankroll);
        if (bet <= 0) break;

        vector<Card> player, dealer;
        player.push_back(deal(deck)); dealer.push_back(deal(deck));
        player.push_back(deal(deck)); dealer.push_back(deal(deck));

        cout << "Player: "; printHand(player); cout << " (" << handValue(player) << ")\n";
        cout << "Dealer: "; printHand(dealer, true); cout << endl;

        // Step 1: Check for Blackjack
        bool playerBJ = isBlackjack(player);
        bool dealerBJ = isBlackjack(dealer);

        if (playerBJ || dealerBJ) {
            cout << "Dealer: "; printHand(dealer); cout << " (" << handValue(dealer) << ")\n";
            if (playerBJ && dealerBJ) {
                cout << "Push! Both have Blackjack.\n";
            } else if (playerBJ) {
                cout << "Blackjack! You win 1.5x your bet.\n";
                bankroll += bet * 1.5;
            } else {
                cout << "Dealer has Blackjack. You lose.\n";
                bankroll -= bet;
            }
            continue;
        }

        bool canDouble = (bankroll >= bet);
        bool playerBusted = false;
        char action;

        while (true) {
            action = promptAction(canDouble);

            if (action == 'h') { // Hit
                player.push_back(deal(deck));
                cout << "Player: "; printHand(player); cout << " (" << handValue(player) << ")\n";
                if (handValue(player) > 21) {
                    cout << "You busted!\n";
                    bankroll -= bet;
                    playerBusted = true;
                    break;
                }
            } else if (action == 'd' && canDouble) { // Double
                bankroll -= bet; // Deduct extra
                bet *= 2;
                player.push_back(deal(deck));
                cout << "You doubled down.\n";
                cout << "Player: "; printHand(player); cout << " (" << handValue(player) << ")\n";
                if (handValue(player) > 21) {
                    cout << "You busted!\n";
                    playerBusted = true;
                }
                break;
            } else if (action == 's') { // Stand
                break;
            }
        }

        if (!playerBusted) {
            dealerPlay(dealer, deck);
            cout << "Dealer: "; printHand(dealer); cout << " (" << handValue(dealer) << ")\n";

            int playerTotal = handValue(player);
            int dealerTotal = handValue(dealer);

            if (dealerTotal > 21) {
                cout << "Dealer busts! You win.\n";
                bankroll += bet;
            } else if (playerTotal > dealerTotal) {
                cout << "You win!\n";
                bankroll += bet;
            } else if (playerTotal < dealerTotal) {
                cout << "Dealer wins.\n";
                bankroll -= bet;
            } else {
                cout << "Push (tie).\n";
            }
        }

        cout << "Bankroll: $" << bankroll << "\n\n";
    }

    cout << "Game over. Bankroll: $" << bankroll << endl;
    return 0;
}
