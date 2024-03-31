# cpp-telegram-lib
Small library to send messages to Telegram from any C/C++ microcontroller e.g. esp8266

Telegram tg("6536508266:AAE1ktOcXhC2SyCA5jNi---your-data", "162--chatId");
tg.setLogger(loggerCallback); // optional
tg.setClient(send);           // any way to send http
tg.sendMessage("hello");

void loggerCallback(const char * m) {
    Serial.print("LOGGER: ");
    Serial.println(m);
}

void send(const char data[]) {
    //any way to run a get request to url in data[]
}

# how to get required params to access the bot: 
Post one message from User to the Bot.
Open https://api.telegram.org/bot/getUpdates page.
Find this message and navigate to the result->message->chat->id key.
Use this ID as the [chat_id] parameter to send personal messages to the User.
https://core.telegram.org/bots/api#available-methods
