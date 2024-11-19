#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void color(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

void displayCriteria() {
    // Main heading color
    color(14); // Light Yellow
    cout << endl << "POINTS BREAKDOWN" << endl << endl;
    color(14); // Light Yellow for Length section heading
    cout << "Length:\n";

    color(15); // White for text
    color(15);
    cout << "  - 8-12 characters: ";
    color(10); cout << "+ 2 "; color(15); cout << "points\n"; // Light Green for +2 points
    color(15);
    cout << "  - 13-20 characters: ";
    color(10); cout << "+ 4 "; color(15); cout << "points\n"; // Light Green for +4 points
    color(15);
    cout << "  - 21-30 characters: ";
    color(10); cout << "+ 6 "; color(15); cout << "points\n\n"; // Light Green for +6 points

    // Character Diversity Section
    color(14); // Light Yellow for Character Diversity section heading
    cout << "Character Diversity:\n";

    // Lowercase letters
    color(9); // Light Blue for subheading
    cout << "  - Lowercase letters:\n";
    color(15); cout << "      1-3: "; color(10); cout << "+1 "; color(15); cout << "point\n"; // Light Green for +1 point
    color(15); cout << "      4 or more: "; color(10); cout << "+2 "; color(15); cout << "points\n"; // Light Green for +2 points

    // Uppercase letters
    color(11); // Light Aqua for subheading
    cout << "  - Uppercase letters:\n";
    color(15); cout << "      1-3: "; color(10); cout << "+1 "; color(15); cout << "point\n"; // Light Green for +1 point
    color(15); cout << "      4 or more: "; color(10); cout << "+2 "; color(15); cout << "points\n"; // Light Green for +2 points

    // Digits
    color(6); // Light Purple for subheading
    cout << "  - Digits:\n";
    color(15); cout << "      1-2: "; color(10); cout << "+1 "; color(15); cout << "point\n"; // Light Green for +1 point
    color(15); cout << "      3-5: "; color(10); cout << "+2 "; color(15); cout << "points\n"; // Light Green for +2 points
    color(15); cout << "      6 or more: "; color(10); cout << "+3 "; color(15); cout << "points\n"; // Light Green for +3 points

    // Special characters
    color(13); // Light Blue for subheading
    cout << "  - Special characters:\n";
    color(15); cout << "      1-3: "; color(10); cout << "+1 "; color(15); cout << "point\n"; // Light Green for +1 point
    color(15); cout << "      4-6: "; color(10); cout << "+2 "; color(15); cout << "points\n"; // Light Green for +2 points
    color(15); cout << "      7 or more: "; color(10); cout << "+3 "; color(15); cout << "points\n\n"; // Light Green for +3 points

    // Penalties Section
    color(14); // Light Yellow for Penalties section heading
    cout << "Penalties:\n";

    // Repeated characters
    color(9); // Light Purple for subheading
    cout << "  - Repeated characters:\n";
    color(15); cout << "      1-2 repeats: "; color(12); cout << "-1 "; color(15); cout << "point\n"; // Light Green for -1 point
    color(15); cout << "      3-4 repeats: "; color(12); cout << "-2 "; color(15); cout << "points\n"; // Light Green for -2 points
    color(15); cout << "      5 or more repeats: "; color(12); cout << "-3 "; color(15); cout << "points\n"; // Light Green for -3 points

    // Consecutive sequences
    color(11); // Light Aqua for subheading
    cout << "  - Consecutive sequences:\n";
    color(15); cout << "      1 sequence of 3 characters: "; color(12); cout << "-1 "; color(15); cout << "point\n"; // Light Green for -1 point
    color(15); cout << "      2 or more sequences: "; color(12); cout << "-2 "; color(15); cout << "points\n\n"; // Light Green for -2 points

    // Bonus Section
    color(14); // Light Yellow for Bonus section heading
    cout << "Bonus:\n";

    color(15); // Light Blue for subheading
    cout << "  - 3 character groups: "; color(10); cout << "+2 "; color(15); cout << "points\n"; // Light Green for +2 points
    color(15); // Light Blue for subheading
    cout << "  - 4 character groups: "; color(10); cout << "+4 "; color(15); cout << "points\n\n"; // Light Green for +4 points

    // Password Strength Based on Points
    color(14); // Light Yellow for Strength Based on Points section heading
    cout << "\nPassword Strength Based on Points:\n";
    color(15); // White for text
    cout << "0 to 4 points: "; color(4); cout << "Very Weak\n"; // Light Purple for Very Weak
    color(15); cout << "5 to 9 points: "; color(12); cout << "Weak\n"; // Light Purple for Weak
    color(15); cout << "10 to 14 points: "; color(2); cout << "Moderate\n"; // Light Aqua for Moderate
    color(15); cout << "15 to 19 points: "; color(2); cout << "Strong\n"; // Light Green for Strong
    color(15); cout << "20 to 24 points: "; color(10); cout << "Very Strong\n"; // Light Green for Very Strong
    color(15); cout << "25+ points: "; color(11); cout << "Excellent\n"; // Light Blue for Excellent
    color(15); // Reset to white after finishing the color coding
}

void menu(bool showDetails) {
    system("cls");
    color(14); // Yellow for title
    cout << "PASSWORD STRENGTH CHECKER MADE BY AMMAR ANAS";
    cout << endl << endl;
    color(15); // White for text
    cout << "Enter a password to check its strength.";
    color(10); // Green for password limit
    cout << "\nPassword can be max 30 characters.";
    color(12); // Red for space warning
    cout << "\nPassword cannot include any spaces." << endl << endl;
    color(15);
    cout << "Press '";
    color(10);
    cout << "D";
    color(15);
    cout << "' to toggle point breakdown.\n";

    if (showDetails) {
        displayCriteria();
    }

    color(15); // White for default text
    cout << "\nPress '";
    color(10);
    cout << "Enter";
    color(15);
    cout << "' to continue to password entry.\n";
    color(15);
    cout << "Press '";
    color(12);
    cout << "Q";
    color(15);
    cout << "' to exit.\n\n";
}

int calculatePasswordStrength(const char password[], int length, int& lengthPoints, int& lowercasePoints, int& uppercasePoints, int& digitPoints, int& specialPoints, int& repeatsPenalty, int& sequencePenalty, int& bonusPoints) {
    int points = 0;

    // Length Points
    if (length >= 8 && length <= 12) {
        lengthPoints = 2;
        points += 2;
    }
    else if (length >= 13 && length <= 20) {
        lengthPoints = 4;
        points += 4;
    }
    else if (length >= 21) {
        lengthPoints = 6;
        points += 6;
    }
    else {
        lengthPoints = 0;
    }

    // Character Diversity Points
    int lowercase = 0, uppercase = 0, digits = 0, special = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) lowercase++;
        else if (isupper(password[i])) uppercase++;
        else if (isdigit(password[i])) digits++;
        else special++;
    }

    if (lowercase >= 1 && lowercase <= 3) {
        lowercasePoints = 1;
        points += 1;
    }
    else if (lowercase > 3) {
        lowercasePoints = 2;
        points += 2;
    }
    else {
        lowercasePoints = 0;
    }

    if (uppercase >= 1 && uppercase <= 3) {
        uppercasePoints = 1;
        points += 1;
    }
    else if (uppercase > 3) {
        uppercasePoints = 2;
        points += 2;
    }
    else {
        uppercasePoints = 0;
    }

    if (digits >= 1 && digits <= 2) {
        digitPoints = 1;
        points += 1;
    }
    else if (digits >= 3 && digits <= 5) {
        digitPoints = 2;
        points += 2;
    }
    else if (digits > 5) {
        digitPoints = 3;
        points += 3;
    }
    else {
        digitPoints = 0;
    }

    if (special >= 1 && special <= 3) {
        specialPoints = 1;
        points += 1;
    }
    else if (special >= 4 && special <= 6) {
        specialPoints = 2;
        points += 2;
    }
    else if (special > 6) {
        specialPoints = 3;
        points += 3;
    }
    else {
        specialPoints = 0;
    }

    // Repetition Penalty Points
    int repeats = 0;
    for (int i = 1; i < length; i++) {
        if (password[i] == password[i - 1]) repeats++;
    }
    if (repeats >= 1 && repeats <= 2) {
        repeatsPenalty = -1;
        points -= 1;
    }
    else if (repeats >= 3 && repeats <= 4) {
        repeatsPenalty = -2;
        points -= 2;
    }
    else if (repeats > 4) {
        repeatsPenalty = -3;
        points -= 3;
    }
    else {
        repeatsPenalty = 0;
    }

    // Sequence Penalty Points
    int sequences = 0;
    for (int i = 2; i < length; i++) {
        if ((password[i] == password[i - 1] + 1) && (password[i - 1] == password[i - 2] + 1)) {
            sequences++;
        }
    }
    if (sequences == 1) {
        sequencePenalty = -1;
        points -= 1;
    }
    else if (sequences > 1) {
        sequencePenalty = -2;
        points -= 2;
    }
    else {
        sequencePenalty = 0;
    }

    // Bonus Points for Mixed Character Groups
    int groups = (lowercase > 0) + (uppercase > 0) + (digits > 0) + (special > 0);
    if (groups == 3) {
        bonusPoints = 2;
        points += 2;
    }
    else if (groups == 4) {
        bonusPoints = 4;
        points += 4;
    }
    else {
        bonusPoints = 0;
    }

    return points;
}

void displayStrength(int points, int lengthPoints, int lowercasePoints, int uppercasePoints, int digitPoints, int specialPoints, int repeatsPenalty, int sequencePenalty, int bonusPoints, const char password[31]) {
    color(14);
    cout << "\n\nPassword Strength: ";
    if (points <= 0) {
        color(4);  // Red for very weak 4 12 2 2 10 11
        cout << "Very Weak";
    }
    else if (points <= 4) {
        color(12);  // Red for weak
        cout << "Weak";
    }
    else if (points <= 9) {
        color(2);  // Yellow for moderate
        cout << "Moderate";
    }
    else if (points <= 15) {
        color(2);  // Green for strong
        cout << "Strong";
    }
    else if (points <= 20) {
        color(10);  // Blue for very strong
        cout << "Very Strong";
    }
    else {
        color(11);  // Cyan for excellent
        cout << "Excellent";
    }
    color(15);  // Reset to white
    cout << endl;
    color(14);
    cout << "\nPassword: ";
    color(15);
    cout << password;
    // Display point breakdown
    color(14);
    cout << "\n\nPoint Breakdown:\n";
    color(15);
    cout << "\nLength Points: ";
    color(10);
    cout << lengthPoints << endl;
    color(15);
    cout << "Lowercase Points: ";
    color(10);
    cout << lowercasePoints << endl;
    color(15);
    cout << "Uppercase Points: ";
    color(10);
    cout << uppercasePoints << endl;
    color(15);
    cout << "Digit Points: ";
    color(10);
    cout << digitPoints << endl;
    color(15);
    cout << "Special Character Points: ";
    color(10);
    cout << specialPoints << endl;
    color(15);
    cout << "Repeats Penalty: ";
    color(13);
    cout << repeatsPenalty << endl;
    color(15);
    cout << "Sequence Penalty: ";
    color(13);
    cout << sequencePenalty << endl;
    color(15);
    cout << "Bonus Points: ";
    color(12);
    cout << bonusPoints << endl;
    color(15);
    cout << "Total Points: ";
    color(10);
    cout << points << endl;
    color(15);
}

int main() {
    bool showDetails = false;

    while (true) {
        menu(showDetails);
        char ch = _getch();
        if (ch == 13) { // Enter key
            system("cls");
            cout << "Enter your Password: ";
            char password[31];
            int passwordsize = 0;
            while (true) {
                ch = _getch();
                if (ch == 13) break;
                if (ch == 32) continue;
                if (ch == 8 && passwordsize > 0) {
                    passwordsize--;
                    cout << "\b \b";
                    continue;
                }
                if (passwordsize < 30) {
                    password[passwordsize++] = ch;
                    color(8);
                    cout << '*';
                    color(15);
                }
            }
            password[passwordsize] = '\0';

            int lengthPoints = 0, lowercasePoints = 0, uppercasePoints = 0, digitPoints = 0, specialPoints = 0, repeatsPenalty = 0, sequencePenalty = 0, bonusPoints = 0;
            int points = calculatePasswordStrength(password, passwordsize, lengthPoints, lowercasePoints, uppercasePoints, digitPoints, specialPoints, repeatsPenalty, sequencePenalty, bonusPoints);
            displayStrength(points, lengthPoints, lowercasePoints, uppercasePoints, digitPoints, specialPoints, repeatsPenalty, sequencePenalty, bonusPoints, password);
            _getch();
        }
        else if (ch == 'D' || ch == 'd') {
            showDetails = !showDetails; // Toggle point breakdown display
        }
        else if (ch == 'Q' || ch == 'q') {
            break; // Exit the program
        }
    }
    return 0;
}