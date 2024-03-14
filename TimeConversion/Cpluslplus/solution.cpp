#include <bits/stdc++.h>
#include <regex>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // Separate string into 3 variables: AM/PM, hours, and everything else
    std::string timeOfDay = s.substr(s.size() - 2);
    std::string hours = s.substr(0, 2);
    std::string minutesAndSeconds = s.substr(2, (s.size() - 4));
    std::string result;
    
    if (timeOfDay == "AM") {
        // If it's AM, we only have to do something if it's hour 12 (change 12 -> 00)
        if (hours == "12") {
            result = "00" + minutesAndSeconds;
        }
        else {
            result = hours + minutesAndSeconds;
        }
    }
    else {
        // If it's PM, we add +12 to the hours UNLESS it's 12PM
        if (hours == "12") {
            result = hours + minutesAndSeconds;
        }
        else {
            result = std::to_string(stoi(hours) + 12) + minutesAndSeconds;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
