// AREEBA ARIF

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class numCard
{

public:
    int ranktoint(string r)
    {
    	int rank;
        if (r=="2")
        {
            rank = 2;
        }
        else if (r=="3")
        {
            rank = 3;
        }
        else if (r=="4")
        {
            rank = 4;
        }
        else if (r=="5")
        {
            rank = 5;
        }
        else if (r=="6")
        {
            rank = 6;
        }
        else if (r=="7")
        {
            rank = 7;
        }
        else if (r=="8")
        {
            rank = 8;
        }
        else if (r=="9")
        {
            rank = 9;
        }
        else if (r=="10")
        {
            rank = 10;
        }
        return rank;
    }

    void display(int r, char s)
    {
        cout << "Card Rank: " << r << endl;
        cout << "Card Suit: " << s << endl;
    }
};

class faceCard
{

public:
    int ranktoint(string r)
    {
    	int rank;
        if (r=="J")
        {
            rank = 11;
        }
        else if (r=="Q")
        {
            rank = 12;
        }
        else if (r=="K")
        {
            rank = 13;
        }
        else if (r=="A")
        {
            rank = 14;
        }
        return rank;
    }

    char inttochar(int rank)
    {
        if (rank == 11)
        {
            return 'J';
        }
        else if (rank == 12)
        {
            return 'Q';
        }
        else if (rank == 13)
        {
            return 'K';
        }
        else if (rank == 14)
        {
            return 'A';
        }
        return 'X';
    }

    void display(int r, char s)
    {
        cout << "Card Rank: " << inttochar(r) << endl;
        cout << "Card Suit: " << s << endl;
    }
};

class Card : public numCard, public faceCard
{
private:
    int rank;
    char suit;

public:
    Card()
    {
        rank = 0;
        suit = '0';
    }

    Card(string r, char s) : numCard(), faceCard()
    {
        if (r=="2"||r=="3"||r=="4"||r=="5"||r=="6"||r=="7"||r=="8"||r=="9"||r=="10")
        {
            rank = numCard::ranktoint(r);
            if ((s == 'D') || (s == 'S') || (s == 'C') || (s == 'H'))
            {
                suit = s;
            }
        }
        else
        {
            rank = faceCard::ranktoint(r);
            if ((s == 'D') || (s == 'S') || (s == 'C') || (s == 'H'))
            {
                suit = s;
            }
        }
    }

    int getrank()
    {
        return rank;
    }

    char getsuit()
    {
        return suit;
    }

	void setrank(int r)
    {
        rank = r;
    }

    void setsuit(char s)
    {
        suit = s;
    }

    void resetCard()
    {
        rank = 0;
        suit = '0';
    }

    void display()
    {
        if (rank < 11)
        {
            numCard::display(rank,suit);
        }
        else
        {
            faceCard::display(rank,suit);
        }
    }
};

class Player
{
protected:
    Card playerCards[52];

public:

    void setCardRank(int r, int i)
    {
        playerCards[i].setrank(r);
    }

    void setCardSuit(char s, int i)
    {
        playerCards[i].setsuit(s);
    }

    int getCardRank(int i)
    {
        return playerCards[i].getrank();
    }
};

class Game;

class back
{
private:
    int lead;
    int end;
    int one_done;
    int p_count;

public:
    friend class Game;

    int getlead()
    {
        return lead;
    }

    int getend()
    {
        return end;
    }

    int getone_done()
    {
        return one_done;
    }

    int getpcount()
    {
        return p_count;
    }

    void setlead(int l)
    {
        lead = l;
    }

    void setend(int e)
    {
        end = e;
    }

    void setone_done(int d)
    {
        one_done = d;
    }

    void setp_count(int p)
    {
        p_count = p;
    }

    friend class Game;
};



class Game
{
protected:
    static const int n = 4;
    Player players[n];

public:
    void shuffle(Card deck[])
    {
        int i, j, tempR;
        char tempS;
        srand(time(0));
        int done[52] = {0};
        for (i = 0; i < 52; i++)
        {
            int count = 0;
            for (j = 0; j < 52; j++)
            {
                if (done[j] == 0)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                break;
            }
            int num1 = rand() % 52;
            int num2 = rand() % 52;
            while (done[num1] == 1 || done[num2] == 1)
            {
                num1 = rand() % 52;
                num2 = rand() % 52;
            }
            done[num1] = 1;
            done[num2] = 1;
            tempR = deck[num1].getrank();
            tempS = deck[num1].getsuit();
            deck[num1].setrank(deck[num2].getrank());
            deck[num1].setsuit(deck[num2].getsuit());
            deck[num2].setrank(tempR);
            deck[num2].setsuit(tempS);
        }
    }

    void distribute(Card deck[])
    {
        int equal_cards, player, cardR, deckPos = 0, i;
        char cardS;
        equal_cards = 52 / n;
        for (player = 0; player < n; player++)
        {
            for (i = 0; i < equal_cards; i++)
            {
                cardR = deck[deckPos].getrank();
                cardS = deck[deckPos++].getsuit();
                players[player].setCardRank(cardR, i);
                players[player].setCardSuit(cardS, i);
                cout << "Player " << player + 1 << " hand: " << endl;
                if (cardR > 10)
                {
                    switch (cardR)
                    {
                    case 11:
                        cout << "J of " << cardS << endl;
                        break;
                    case 12:
                        cout << "Q of " << cardS << endl;
                        break;
                    case 13:
                        cout << "K of " << cardS << endl;
                        break;
                    case 14:
                        cout << "A of " << cardS << endl;
                        break;
                    }
                }
                else
                {
                    cout << cardR << " of " << cardS << endl;
                }
            }
            cout << endl;
        }
    }

    int start(int lead)
    {
        int expected;
        string s_expected;
        cout << "Lead : Please enter the expected rank for this round" << endl;
        cin >> s_expected;
        while ((s_expected != "J") && (s_expected != "Q") && (s_expected != "K") && (s_expected != "A") && (s_expected != "2") && (s_expected != "3") && (s_expected != "4") && (s_expected != "5") && (s_expected != "6") && (s_expected != "7") && (s_expected != "8") && (s_expected != "9") && (s_expected != "10"))
        {
            cout << "Lead: Please enter valid expected rank for this round" << endl;
            cout << "You can enter one of these ranks: 2,3,4,5,6,7,8,9,10,J,Q,K,A" << endl;
            cin >> s_expected;
        }
        if (s_expected == "J")
        {
            expected = 11;
        }
        else if (s_expected == "Q")
        {
            expected = 12;
        }
        else if (s_expected == "K")
        {
            expected = 13;
        }
        else if (s_expected == "A")
        {
            expected = 14;
        }
        if (s_expected=="2")
        {
            expected = 2;
        }
        else if (s_expected=="3")
        {
            expected = 3;
        }
        else if (s_expected=="4")
        {
            expected = 4;
        }
        else if (s_expected=="5")
        {
            expected = 5;
        }
        else if (s_expected=="6")
        {
            expected = 6;
        }
        else if (s_expected=="7")
        {
            expected = 7;
        }
        else if (s_expected=="8")
        {
            expected = 8;
        }
        else if (s_expected=="9")
        {
            expected = 9;
        }
        else if (s_expected=="10")
        {
            expected = 10;
        }
        return expected;
    }

    int challenge(int current_player, Card pile[], int dma_last[], int expected, int num, int lead)
    {
        int challenger, i, lie = 0, filled = 0, j, k = 0, challenged;
        cout << "Which player wants to call bluff?" << endl;
        cin >> challenger;
        while ((challenger != 1) && (challenger != 2) && (challenger != 3) && (challenger != 4))
        {
            cout << "Enter a valid player: 1,2,3, or 4?" << endl;
            cin >> challenger;
        }
        challenger--;
        for (i = 0; i < num; i++)
        {
            if (dma_last[i] != expected)
            {
                lie = 1;
                break;
            }
        }
        challenged = --current_player;
        if (lie == 1)
        {
            cout << "Successful bluff" << endl
                 << "Player " << challenged + 1 << " will have to pick up the pile" << endl;
            for (i = 0; i < 52; i++)
            {
                if (players[challenged].getCardRank(i) != 0)
                {
                    filled++;
                }
                else
                {
                    break;
                }
            }
            for (i = 0; i < 52; i++)
            {
                if (pile[i].getrank() == 0)
                {
                    break;
                }
            }
            for (j = filled; j < filled + i; j++)
            {
                players[challenged].setCardRank(pile[k].getrank(), j);
                k++;
            }
        }
        else
        {
            cout << "Unsuccessful bluff" << endl
                 << "Player " << challenger + 1 << " will have to pick up the pile" << endl;
            for (i = 0; i < 52; i++)
            {
                if (players[challenger].getCardRank(i) != 0)
                {
                    filled++;
                }
                else
                {
                    break;
                }
            }
            for (i = 0; i < 52; i++)
            {
                if (pile[i].getrank() == 0)
                {
                    break;
                }
            }
            for (j = filled; j < filled + i; j++)
            {
                players[challenger].setCardRank(pile[k].getrank(), j);
                k++;
            }
        }
        lead = ++challenger;
        return lead;
    }
    
    int game_end(int current_player)
    {
        if (players[current_player - 2].getCardRank(0) == 0)
        {
            return 1;
        }
        return 0;
    }
    
    back move(int current_player, Card pile[], int passed[], int expected, int p_count)
    {
        int play, num, i, card, j, k, flag = 0;
        string cardstring;
        back values;
        values.lead = current_player; // Add a variable to keep track of the lead player
        values.end = 0;               // game is not ended initially
        values.one_done = 0;
        while (1)
        {
            cout << "Type '0' to pass, Type '1' to play" << endl;
            cin >> play;
            while (play != 0 && play != 1)
            {
                cout << "Invalid input: Please type '0' to pass, Type '1' to play" << endl;
                cin >> play;
            }
            if (play == 0)
            {
                for (i = 0; i < 5; i++)
                {
                    if (passed[i] == current_player - 1)
                    {
                        break;
                    }
                }
                if (i == 5)
                {
                    p_count++;
                    for (i = 0; i < 5; i++)
                    {
                        if (passed[i] == -1)
                        {
                            passed[i] = current_player - 1;
                            break;
                        }
                    }
                }
                cout << "Turn passed for Player" << current_player << endl;
                if (p_count == n)
                {
                    cout << "All players passed. Round ended." << endl;
                    values.one_done = 1;
                    p_count = 0;
                    values.p_count = p_count;
                    // Remove pile from play
                    for (int i = 0; i < 52; i++)
                    {
                        pile[i].resetCard();
                    }
                    // Reset passed
                    for (int i = 0; i < 4; i++)
                    {
                        passed[i] = -1;
                    }
                    // so we're  basically just removing the pile and resetting the players that
                    // passed and starting another round
                    values.lead = current_player;
                    expected = start(values.lead);
                    return values;
                }
                else
                {
                    if (current_player == n)
                    {
                        current_player = 1;
                    }
                    else
                    {
                        current_player++;
                    }
                    values.p_count = p_count;
                    values.lead = current_player;
                    return values;
                }
            }
            else if (play == 1)
            {
                for (i = 0; i < 5; i++)
                {
                    if (passed[i] == current_player - 1)
                    {
                        cout << "You cannot play, You have passed once before so you can not play again in this round." << endl;
                        cout << "Your turn has been skipped." << endl;
                        break;
                    }
                }
                if (i == 5)
                {
                    cout << endl << "Player " << current_player << "'s current cards:" << endl;
                    for (i = 0; i < 52; i++)
                    {
                        if (players[current_player - 1].getCardRank(i) == 0)
                        {
                            break;
                        }
                        if (players[current_player - 1].getCardRank(i) > 10)
                        {
                            switch (players[current_player - 1].getCardRank(i))
                            {
                            case 11:
                                cout << "J" << endl;
                                break;
                            case 12:
                                cout << "Q" << endl;
                                break;
                            case 13:
                                cout << "K" << endl;
                                break;
                            case 14:
                                cout << "A" << endl;
                                break;
                            }
                        }
                        else
                        {
                            cout << players[current_player - 1].getCardRank(i) << endl;
                        }
                    }
                    cout << "How many cards do you want to play?" << endl;
                    cin >> num;
                    while (num < 0 || num > 4)
                    {
                        cout << "Invalid input :( You can play at least 1 or at most 4 cards\nThere are only 4 cards of one rank" << endl;
                        cout << "How many cards do you want to play?\n"
                             << endl;
                        cin >> num;
                    }
                    int dma_last[4];
                    for (i = 0; i < num; i++)
                    {
                        cout << "Enter card rank:" << endl;
                        cin >> cardstring;
                        while ((cardstring != "J") && (cardstring != "Q") && (cardstring != "K") && (cardstring != "A") && (cardstring != "2") && (cardstring != "3") && (cardstring != "4") && (cardstring != "5") && (cardstring != "6") && (cardstring != "7") && (cardstring != "8") && (cardstring != "9") && (cardstring != "10"))
				        {
				            cout << "Please enter valid card rank" << endl;
                            cout << "You can enter one of these ranks: 2,3,4,5,6,7,8,9,10,J,Q,K,A" << endl;
                            cin >> cardstring;
				        }
				        if (cardstring == "J")
				        {
				            card = 11;
				        }
				        else if (cardstring == "Q")
				        {
				            card = 12;
				        }
				        else if (cardstring == "K")
				        {
				            card = 13;
				        }
				        else if (cardstring == "A")
				        {
				            card = 14;
				        }
				        if (cardstring=="2")
				        {
				            card = 2;
				        }
				        else if (cardstring=="3")
				        {
				            card = 3;
				        }
				        else if (cardstring=="4")
				        {
				            card = 4;
				        }
				        else if (cardstring=="5")
				        {
				            card = 5;
				        }
				        else if (cardstring=="6")
				        {
				            card = 6;
				        }
				        else if (cardstring=="7")
				        {
				            card = 7;
				        }
				        else if (cardstring=="8")
				        {
				            card = 8;
				        }
				        else if (cardstring=="9")
				        {
				            card = 9;
				        }
				        else if (cardstring=="10")
				        {
				            card = 10;
				        }
                        flag = 0;
                        for (k = 0; k < 52; k++)
                        {
                            if (players[current_player - 1].getCardRank(k) == card)
                            {
                                flag = 1;
                                players[current_player - 1].setCardRank(0, k); // remove the card from player's hand
                                int x;
                                for (x = k; x < 52; x++)
                                {
                                    if (x == 51)
                                    {
                                        break;
                                    }
                                    players[current_player - 1].setCardRank(players[current_player - 1].getCardRank(x + 1), x);
                                }
                                dma_last[i] = card; // add the card to the last played cards
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            cout << "Invalid card. You don't have this card in your hand." << endl;
                            i--; // retry the current card input
                        }
                    }
                    // Call the challenge function here
                    cout << "Does any player want to call bluff? Enter 1 for yes, 0 for no\n";
                    int bluff;
                    cin >> bluff;
                    while (bluff != 0 && bluff != 1)
                    {
                        cout << "Invalid input. Enter 1 for yes, 0 for no" << endl;
                        cin >> bluff;
                    }
                    if (bluff == 1)
                    {
                        values.lead = challenge(current_player, pile, dma_last, expected, num, values.lead);
                        values.one_done = 1;
                        values.p_count = 0;
                        p_count = 0;
                        for (int i = 0; i < 52; i++)
                        {
                            pile[i].resetCard();
                        }
                    }
                    else if (bluff == 0)
                    {
                        if (current_player == n)
                        {
                            current_player = 1;
                        }
                        else
                        {
                            current_player++;
                        }
                        values.lead = current_player;
                    }
                    values.end = game_end(current_player);
                    for (int i = 0; i < 4; i++)
                    {
                        dma_last[i] = 0;
                    }
                    return values;
                }
            }
        }
    }
};


int main()
{
    Card pile[52];

    Card deck[52] = {Card("2", 'D'), Card("2", 'S'), Card("2", 'C'), Card("2", 'H'),
                     Card("3", 'D'), Card("3", 'S'), Card("3", 'C'), Card("3", 'H'),
                     Card("4", 'D'), Card("4", 'S'), Card("4", 'C'), Card("4", 'H'),
                     Card("5", 'D'), Card("5", 'S'), Card("5", 'C'), Card("5", 'H'),
                     Card("6", 'D'), Card("6", 'S'), Card("6", 'C'), Card("6", 'H'),
                     Card("7", 'D'), Card("7", 'S'), Card("7", 'C'), Card("7", 'H'),
                     Card("8", 'D'), Card("8", 'S'), Card("8", 'C'), Card("8", 'H'),
                     Card("9", 'D'), Card("9", 'S'), Card("9", 'C'), Card("9", 'H'),
                     Card("10", 'D'), Card("10", 'S'), Card("10", 'C'), Card("10", 'H'),
                     Card("J", 'D'), Card("J", 'S'), Card("J", 'C'), Card("J", 'H'),
                     Card("Q", 'D'), Card("Q", 'S'), Card("Q", 'C'), Card("Q", 'H'),
                     Card("K", 'D'), Card("K", 'S'), Card("K", 'C'), Card("K", 'H'),
                     Card("A", 'D'), Card("A", 'S'), Card("A", 'C'), Card("A", 'H')};
                     
    int i, j;
    Game g1;

    int player_cards[5][52] = {0};
    int lead;
    int passed[5] = {-1, -1, -1, -1, -1};

    cout << "Initial deck." << endl;

    for (i = 0; i < 52; i++)
    {
        deck[i].display();
    }
    cout << endl;
    g1.shuffle(deck); // shuffled deck

    cout << "Shuffled deck." << endl;

    for (i = 0; i < 52; i++)
    {
        deck[i].display();
    }
    cout << endl;
    cout << endl;
    g1.distribute(deck);
    
    cout << "Which player will be the lead?\n";
    cin >> lead;
    while (lead != 1 && lead != 2 && lead != 3 && lead != 4)
    {
        cout << "Enter a valid player: 1,2,3, or 4?" << endl;
        cin >> lead;
    }
    int expected = g1.start(lead);
    
    back round;
    round = g1.move(lead, pile, passed, expected, 0);
    if (round.getend() == 1)
    {
        cout << "Game ended!\nPlayer " << round.getlead() << " has won!\n";
    }
    else
    {
        while (round.getend() == 0)
        {

            if (round.getone_done() == 1)
            {
                cout << "The lead is player:" << round.getlead() + 1;
                expected = g1.start(round.getlead());
                cout << "The current player is player: " << round.getlead();
                round = g1.move(round.getlead(), pile, passed, expected, 0);
            }
            else
            {
                cout << "The current player is player:" << round.getlead();
                round = g1.move(round.getlead(), pile, passed, expected, 0);
            }
            round.setone_done(0);
        }
        cout << "Game ended!" << endl << "Player" << round.getlead()-1 << "has won!" << endl;
    }
};