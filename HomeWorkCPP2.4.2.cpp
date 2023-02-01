#include <iostream>
#include <string>
#include <fstream>

class Arrange {
public:
    std::string line;
    std::string sortsity;
    Arrange() {}
    Arrange(std::string sity_, std::string street_, int house_ = 0, int flat_ = 0) {
        sortsity = sity_;
        _sity = sity_;
        _street = street_;
        _house = house_;
        _flat = flat_;
    }
    //~Arrange();
    void get_output_address();
private:
    std::string _sity;
    std::string _street;
    int _house = 0;
    int _flat = 0;
};

void Arrange::get_output_address() {
    line = _sity + ", " + _street + ", " + std::to_string(_house) + ", " + std::to_string(_flat);
}

void sorting(Arrange*& arr_address,int& size){
    bool fin = true;
    Arrange max;
    do {
           fin = false;
        for (int i = size - 1; i > 0; i--) {
            if (arr_address[i - 1].sortsity > arr_address[i].sortsity) {
                max = arr_address[i - 1];
                arr_address[i - 1] = arr_address[i];
                arr_address[i] = max;
                fin = true;
            }
        }
    } while (fin);
}

int main()
{
    int size = 0, house = 0, flat = 0;
    std::string sity;
    std::string street;
    Arrange* arr_address;
    Arrange address(sity, street, house, flat);
    std::ifstream file_in("in.txt");
    if (file_in.is_open()) {
        file_in >> size;
        arr_address = new Arrange[size];
        for (int i = 0; i < size; i++) {
            file_in >> sity;
            file_in >> street;
            file_in >> house;
            file_in >> flat;
            arr_address[i] = { sity, street, house, flat };
        }
        file_in.close();
    }
    else {
        std::cout << "Ошибка открытия файла in" << std::endl;
        return 1;
    }
    sorting(arr_address, size);
    std::ofstream file_out("out.txt");
    if (file_out.is_open()) {
        file_out << size;
        file_out << "\n";
        for (int i = 0; i < size; i++) {
            arr_address[i].get_output_address();
            file_out << arr_address[i].line << "\n";
        }
        file_out << std::endl;
        file_out.close();
    }
    else {
        std::cout << "Ошибка открытия файла out" << std::endl;
        return 1;
    }
    delete[] arr_address;
    arr_address = nullptr;
}