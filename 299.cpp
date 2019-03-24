/*
Bulls and Cows https://leetcode.com/problems/bulls-and-cows/description/
*/

string getHint(string secret, string guess) {
    int num1 = 0;
    int num2 = 0;
    map<char, int> m1;
    map<char, int> m2;
    for (int i = 0; i<min(secret.size(), guess.size()); i++) {
        if (secret[i] == guess[i])
            num1++;
        else {
            m1[secret[i]]++;
            m2[guess[i]]++;
            if (m1[guess[i]]!=0) {
                m2[guess[i]]--;
                m1[guess[i]]--;
                num2++;
            }
            if (m2[secret[i]]!= 0) {
                m1[secret[i]]--;
                m2[secret[i]]--;
                num2++;
            }
        }
    }
    return to_string(num1) + "A" + to_string(num2) + "B";
}