#include <iostream>

// Hàm tính thời gian gặp nhau
double timeToMeet(double x1, double v1, double x2, double v2) {
    return (x2 - x1) / (v1 - v2);
}

// Hàm tính vị trí gặp nhau
double positionAtTime(double x, double v, double t) {
    return x + v * t;
}

int main() {
    double x1, v1, x2, v2;
    std::cout << "Nhập vị trí xuất phát và vận tốc của xe 1 (x1, v1): ";
    std::cin >> x1 >> v1;
    std::cout << "Nhập vị trí xuất phát và vận tốc của xe 2 (x2, v2): ";
    std::cin >> x2 >> v2;

    double t = timeToMeet(x1, v1, x2, v2);
    if (t >= 0) {
        std::cout << "Hai xe sẽ gặp nhau sau " << t << " giờ." << std::endl;
        double meetPosition = positionAtTime(x1, v1, t);
        std::cout << "Vị trí gặp nhau: " << meetPosition << std::endl;
    } else {
        std::cout << "Hai xe sẽ không bao giờ gặp nhau." << std::endl;
    }

    return 0;
}
