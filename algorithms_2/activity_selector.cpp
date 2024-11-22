#include <iostream>
using namespace std;

typedef struct activity {
  int s, f;
} ACT;

//assume activities sorted by ascending finishing time
ACT* activity_selector(ACT activities[], int size) {
  ACT* selected_activities = new ACT[size];

  selected_activities[0] = activities[0];
  for (int i = 1; i < size; i++) {
    selected_activities[i] = {-1, -1};
  }

  int i_lst_s_act = 0;    //index of last selected activity
  for (int i = 1; i < size; i++) {
    if (activities[i].s >= selected_activities[i_lst_s_act].f) {
      i_lst_s_act++;
      selected_activities[i_lst_s_act] = activities[i];
    }
  }

  return selected_activities;
}

int main() {
  const int size = 11;
  ACT acts[11] = {{1,4},{3,5},{0,6},{5,7},{3,9},{5,9},
                {6,10},{7,11},{8,12},{2,14},{12,16}};
  ACT* sel_acts = activity_selector(acts, size);

  for (int i = 0; i < size; i++) {
    if (sel_acts[i].s != -1) {
      cout << sel_acts[i].s << "-" << sel_acts[i].f << endl;
    }
  }
}
