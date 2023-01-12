#include <iostream>
#include <exception>
#include <string>
using namespace std;


class TimeServer {
public:
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    string GetCurrentTime() {
		try {
			last_fetched_time = AskTimeServer();
			return (last_fetched_time);
		} catch (system_error error) {
			return (last_fetched_time);
		}
	}
    

private:
    string last_fetched_time = "00:00:00";
};


