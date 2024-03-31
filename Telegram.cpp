#include <cstdio>
#include <string>

class Telegram {
    public: 
    Telegram() {

    }

    Telegram(char * accessToken, char * chat_id) {
        _accessToken = accessToken; 
        _chat_id = chat_id;
    }

    Telegram(char * accessToken, char * chat_id, void (*fn)(const char[])) {
        _accessToken = accessToken; 
        _chat_id = chat_id;
        
    }

    void setClient(void (*fn)(const char[])) {
        httpGet = fn; 
        log("Http client is set");
    }

    void setLogger(void (*fn)(const char[])) {
        logger = fn; 
        log("Logger initiated");
    }

    void setParams(char * accessToken, char * chat_id) {
        _accessToken = accessToken;
        _chat_id = chat_id;
    }

    void log(const char s[]) {
        if (logger == NULL) return; 
        logger(s);
    }

    bool sendMessage(char message[]) {
        log("sendMessage called");
        if (httpGet == NULL) {
            log("Method for get request not privided!");
            return false; 
        }
        std::string token(_accessToken);
        std::string id(_chat_id);
        std::string m(message);

        std::string result = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + id + "&text=" + message + "&parse_mode=HTML";

        std::string logMessage("Sending request: ");

        log((logMessage + result).c_str());
        httpGet(result.c_str());

        return true; 
    }

    private: 
        char * _accessToken; 
        char * _chat_id; 
        void (*httpGet)(const char[]); 
        void (*logger)(const char[]);
};
