#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

// COMSC-210 | Lab 13 | Ian Kusmiantoro
// This program tracks the number of points a team scored in a season
// Using vectors instead of arrays of course

int main() {
    const int SEARCH = 67;
    vector<int> scores;

    ifstream fin;
    fin.open("scores.txt");

    // Checking if file input stream is good
    if (fin.good()) {

        // Input data until read fail
        int temp_score;
        while (fin >> temp_score) {
            scores.push_back(temp_score);
        }

        if (scores.empty()) {
            cout << "Scores array is empty, something went wrong." << endl;
        }

        // Output before scores
        cout << "===== Scores =====" << endl;
        for (int score : scores) {
            cout << score << " ";
        }
        cout << endl << endl;
        
        // General Statistical Data
        cout << "First Game: " << scores.front() << endl;
        cout << "Last Game: " << scores.back() << endl;
        cout << "Best Score: " << *max_element(scores.begin(), scores.end()) << endl;
        cout << "Worst Score: " << *min_element(scores.begin(), scores.end()) << endl;

        // Calculate average score using accumulate from numeric
        int total = accumulate(scores.begin(), scores.end(), 0);
        cout << "Average Score: " << static_cast<double>(total) / scores.size() << endl;

        // Sort using algorithm
        cout << endl;
        sort(scores.begin(), scores.end());
        cout << "===== Sorted Scores =====" << endl;
        for (int score : scores) {
            cout << score << " ";
        }
        cout << endl << endl;

        cout << "Median Score: " << scores.at(scores.size() / 2) << endl;

        // Find using iterator and algorithm
        vector<int>::iterator it;
        it = find(scores.begin(), scores.end(), SEARCH);

        // If the iterator didn't reach the end (last element + 1), it managed to find the element
        if (it != scores.end()) {
            // Broken up into 2 to keep it from being too long
            cout << "Team scored " << SEARCH << " points on game ";
            cout << it - scores.begin() << "!" << endl;
        } else {
            cout << "Team did not ever score " << SEARCH << " points on any game. :(" << endl;
        }

        // Wipe the scores for the next season!
        fill(scores.begin(), scores.end(), 0);
        cout << endl;
        cout << "===== Wiped Scores =====" << endl;
        for (int score : scores) {
            cout << score << " ";
        }
        cout << endl << endl;

        fin.close();
    } else {
        cout << "Error in accessing the file!" << endl;
    }

    return 0;
}