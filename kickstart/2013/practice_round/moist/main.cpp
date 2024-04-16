#include <iostream>
#include <vector>
#include <string>

int main() 
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        std::cin.ignore(1);

        std::string curr;
        std::string last;
        
        int ans = 0;

        std::getline(std::cin, last);

        for (int j = 1; j < N; j++) {
            std::getline(std::cin, curr);   
            if (curr > last) {
                // in order, move our max
                last = curr;
                continue;
            }
            if (curr < last) {
                // out of order, move count increases, and 
                // max stays the same.
                ans++;
                continue;
            }
        }

        std::cout << "Case #" << i + 1 << ": " << ans << std::endl;
    }
    return 0;
}