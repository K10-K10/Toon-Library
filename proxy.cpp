#include <map>
#include <string>
#include <variant>
#include <iostream>

class JsonValue;

class Proxy {
public:
    Proxy(JsonValue& ref) : ref(ref) {}

    // 次の階層へ
    Proxy operator[](const std::string& key);
    
    // 文字列代入
    Proxy& operator=(const std::string& value);

    // 数値代入
    Proxy& operator=(int value);

    // 出力用
    operator std::string() const;

private:
    JsonValue& ref;
};

class JsonValue {
public:
    std::variant<std::string, std::map<std::string, JsonValue>> data;

    JsonValue() : data(std::map<std::string, JsonValue>{}) {}
};

inline Proxy Proxy::operator[](const std::string& key) {
    if (!std::holds_alternative<std::map<std::string, JsonValue>>(ref.data)) {
        ref.data = std::map<std::string, JsonValue>{};
    }
    auto& obj = std::get<std::map<std::string, JsonValue>>(ref.data);
    return Proxy(obj[key]);
}

inline Proxy& Proxy::operator=(const std::string& value) {
    ref.data = value;
    return *this;
}

inline Proxy& Proxy::operator=(int value) {
    ref.data = std::to_string(value);
    return *this;
}

inline Proxy::operator std::string() const {
    if (std::holds_alternative<std::string>(ref.data)) {
        return std::get<std::string>(ref.data);
    }
    return "[object]";
}

// 直接 toon を JSON の root にする
class toon {
public:
    Proxy operator[](const std::string& key) {
        return Proxy(root)[key];
    }

private:
    JsonValue root;
};

