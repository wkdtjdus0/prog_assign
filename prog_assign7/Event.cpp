#include "Event.h"

int Event::event_counter = 0;

Event::Event() {
    id = event_counter++;
}

Event::Event(string cont): content(cont) {
    id = event_counter++;
}

Event::~Event() {};

int Event::get_id() {
    return id;
}

bool Event::contains(string keyword) {
    if (content.find(keyword) != string::npos)
        return true;
    return false;
}

void Event::print(ostream &out) {
    out << id << ". ";
}

OneDayEvent::OneDayEvent() = default;
OneDayEvent::OneDayEvent(Date d, string str): Event(str), date(d) {}

bool OneDayEvent::relevant_to(Date &d1, Date &d2) {
    return d1 <= date && d2 >= date;
}

void OneDayEvent::print(ostream &out) {
    Event::print(out);
    date.print(out);
    out << ":" << content;
}

PeriodEvent::PeriodEvent() = default;
PeriodEvent::PeriodEvent(Date d1, Date d2, string str): Event(str), begin(d1), end(d2) {}

bool PeriodEvent::relevant_to(Date& d1, Date& d2) {
    return begin <= d1 || d2 <= end;
}

void PeriodEvent::print(ostream &out) {
    Event::print(out);
    begin.print(out);
    out << "-";
    end.print(out);
    out << ":" << content;
}

DeadlineEvent::DeadlineEvent() = default;
DeadlineEvent::DeadlineEvent(Date d, string str): Event(str), deadline(d) {}

bool DeadlineEvent::relevant_to(Date& d1, Date& d2) {
    return d1 <= deadline;
}

void DeadlineEvent::print(ostream &out) {
    Event::print(out);
    out << "~";
    deadline.print(out);
    out << ":" << content;
}

void Event::save(ostream& out) {
    out << id << ". ";
}

void OneDayEvent::save(ostream& out) {
    Event::save(out);
    date.save(out);
    out << " " << content << endl;
}

void PeriodEvent::save(ostream& out) {
    Event::save(out);
    begin.save(out);
    out << "-";
    end.save(out);
    out << " " << content << endl;
}

void DeadlineEvent::save(ostream& out) {
    Event::save(out);
    out << "~";
    deadline.save(out);
    out << " " << content << endl;
}