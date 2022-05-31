#include <array>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

std::string get_device_led() {
    // Return the keyboard's LED path (with existence)
    using std::cout, std::endl;
    namespace fs = std::filesystem;
    int file_count = 0;
    fs::path p;

    while (!fs::exists(p) && !fs::is_regular_file(p)) {
        file_count += 1;
        p = "/sys/class/leds/input" + std::to_string(file_count) + "::scrolllock/brightness";
    }
    if (p.string().empty()) {
        cout << "No devices that have LED(s) found." << endl;
        exit(EXIT_FAILURE);
    }

    return p;
}

bool is_device_led_on(std::string device_led) {
    // Return true if device led is turned on, otherwise return false
    using std::ifstream, std::string, std::cout, std::endl;
    ifstream file(device_led);
    string line;
    string state;

    if (!file.is_open()) {
        cout << "Unable to read: " << device_led << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(file, line)) state += line;
    if (state == "0") return false;
    return true;
}

void exec(const char* command)
{
    // Execute command using the system shell
    using std::array, std::unique_ptr, std::cout, std::endl;
    array<char, 128> buffer;
    unique_ptr<FILE, decltype(&pclose) > pipe(popen(command, "r"), pclose);
    if (!pipe) cout << "Unable to execute command: " << command << endl;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) cout << buffer.data();
}

int main() {
    using std::string, std::cout, std::endl;
    string device_led = get_device_led();
    string state_off = "echo 0 > " + device_led;
    string state_on = "echo 1 > " + device_led;

    if (!is_device_led_on(device_led)) {
        exec(state_on.c_str());
    } else {
        exec(state_off.c_str());
    }

    return EXIT_SUCCESS;
}
