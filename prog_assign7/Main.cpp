#include "EventScheduler.h"

void process_command(EventScheduler scheduler) {
    string command, event_type, date_string, content, keyword;
    while(1) {
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            cin >> event_type;
            cin >> date_string;
            getline(cin, content);
            scheduler.add_event(event_type, date_string, content);
        }
        else if (command == "find") {
            try {
                string date_str1, date_str2;
                cin >> date_string;

                int pos = date_string.find('-');
                date_str1 = date_string.substr(0, pos);
                date_str2 = date_string.substr(pos + 1);

                Date d1(date_str1);
                Date d2(date_str2);
                scheduler.show_relevant_events(d1, d2);
            }
            catch (std::invalid_argument const& ex)
            {
                cout << "Invalid Date String!!" << ex.what() << '\n';
            }
        }
        else if (command == "search") {
            getline(cin, keyword);
            scheduler.search_events(keyword);
        }
        else if (command == "list") {
            scheduler.show_all_events();
        }
        else if (command == "delete") {
            int id;
            cin >> id;
            scheduler.delete_event(id);
        }
        else if (command == "save") {
            string filename;
            cin >> filename;
            scheduler.save(filename);
            cout << "Saved in [" + filename + "]\n";
        }
        else if (command == "exit") {
            break;
        }
    }
}

int main() {
    EventScheduler scheduler;
    scheduler.load_data_file("events.txt");
    process_command(scheduler);

    return 0;
}
