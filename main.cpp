#include <iostream>
#include <string>

std::string parseArcadeCard(const std::string& data) {
    size_t start = data.find('=');
    if (start == std::string::npos) {
        std::cerr << "No '=' found in data.\n";
        return "";
    }
    // Start after '='
    start += 1;

    size_t end = data.find('?', start);
    if (end == std::string::npos) {
        std::cerr << "No '?' found after '=' in data.\n";
        return "";
    }

    // Extract substring between '=' and '?'
    std::string extracted = data.substr(start, end - start);

    // Optional: Remove any non-digit characters if you want strictly digits
    std::string digitsOnly;
    for (char c : extracted) {
        if (isdigit(c)) {
            digitsOnly += c;
        }
    }

    return digitsOnly;
}


int main() {
    std::string card;
    std::cout << "Please swipe the card" << "\n";

    std::getline(std::cin, card);

    std::cout << "Raw Card Data: " << card << std::endl;

    size_t track1_start = card.find("%B");
    size_t track2_start = card.find(";");
    size_t track3_start = card.find("+");

    if (track1_start != std::string::npos) {
        size_t end = card.find("?", track1_start);
        std::string track1 = card.substr(track1_start, end - track1_start + 1);
        std::cout << "Track 1: " << track1 << std::endl;
    }

    if (track2_start != std::string::npos) {
        size_t end = card.find("?", track2_start);
        std::string track2 = card.substr(track2_start, end - track2_start + 1);
        std::cout << "Track 2: " << track2 << std::endl;

        std::string cardNumber = parseArcadeCard(track2);
        if (!cardNumber.empty()) {
            std::cout << "Extracted card number: " << cardNumber << "\n";
        } else {
            std::cerr << "Failed to extract card number.\n";
        }
    }

    if (track3_start != std::string::npos) {
        size_t end = card.find("?", track3_start);
        std::string track3 = card.substr(track3_start, end - track3_start + 1);
        std::cout << "Track 3: " << track3 << std::endl;
    }

    return 0;
}