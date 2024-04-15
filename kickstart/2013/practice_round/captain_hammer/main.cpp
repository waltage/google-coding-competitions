#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{

    int T;
    std::cin >> T;
    std::cout << std::setprecision(9) << std::fixed;

    for (int i = 0; i < T; i++) {
        int V, D;
        std::cin >> V >> D;
        double g = 9.8;
        double angle = asin(D * g / (V * V)) / 2;
        double degrees;
        if (isnan(angle)) {
            degrees = 45.0;
        } else {
            degrees = angle * 180 / M_PI;
        }

        std::cout << "Case #" << i + 1 << ": " << degrees << std::endl;
    }
    return 0;
}
