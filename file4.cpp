#include <vector>
#include <limits>
#include <iostream>
#include <string>
using namespace std;



float mean(const vector<float>& data) {
    if (data.empty()) {
        return 0.0;
    }

    float sum = 0.0;
    for (const auto& value : data) {
        sum += value;
    }
    return sum / static_cast<float>(data.size());
}



pair<float, float> minMax(const vector<float>& data) {
    if (data.empty()) {
        return {
            numeric_limits<float> ::max(),
            numeric_limits<float> ::min()
        };
    }

    float min = data[0];
    float max = data[0];

    for (const auto& value : data) {
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
    }

    return {min, max};
}





size_t argmax(const vector<float>& data) {
    if (data.empty()) {
        return -1;
    }

    size_t max_index = 0;
    float max_value = data[0];

    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] > max_value) {
            max_index = i;
            max_value = data[i];
        }
    }

    return max_index;
}




void sort(vector<float>& data) {
    if (data.size() <= 1) {
        return;
    }

    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] < data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}



bool remove_first_negative_element(vector<int>& vec, int& removed_element) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] < 0) {
            removed_element = vec[i];
            vec.erase(vec.begin() + i);
            return true;
        }
    }

    removed_element = 0;
    return false;
}



string replace(const string& str, const string& old_str, const string& new_str) {
    string result = "";
    size_t pos = 0;
    size_t start = 0;

    while ((pos = str.find(old_str, start)) != string::npos) {
        result += str.substr(start, pos - start);
        result += new_str;
        start = pos + old_str.length();
    }

    result += str.substr(start);
    return result;
}



vector<string> split(const string& str, char sep) {
    vector<string> result;
    string test = "";
	bool notp = false;
    for (char c : str) {
        if (c != sep) {
            notp = true;
            break;
        }
    }
    
    if (!notp) return result;
    
    for (char c : str) {
        if (c == sep) {
            if (!test.empty()) {
                result.push_back(test);
                test = "";
            }
        } 
        else {
            test += c;
        }
    }

    if (!test.empty()) {
        result.push_back(test);
    }

    return result;
}




std::string join(const std::vector<std::string>& strings, const std::string& sep) {
    string result;
    if (strings.empty()) {
        return result;
    }
    result += strings[0];
    for (size_t i = 1; i < strings.size(); ++i) {
        result += sep + strings[i];
    }

    return result;
}






int main() {
    vector<std::string> arr = {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
    string str = join(arr, " ");
    cout << str << endl; 
    return 0;
}


