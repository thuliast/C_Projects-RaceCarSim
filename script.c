#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[30];
  char firstPlaceRaceCarColor[12];
};

struct RaceCar {
  char driverName[30];
  char raceCarColor[12];
  int totalLapTime;
};

// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown() {
  printf("Racers Ready! In...\n");
  for (int i = 5; i > 0; i--) {
    printf("%i\n", i);
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d\n", race.currentLap);
  printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!\n");
}
// Logic functions section
int calculateTimeToCompleteLap() {
  int speed;
  int acceleration;
  int nerves;

  speed = (rand() % 3) + 1;
  acceleration = (rand() % 3) + 1;
  nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar *raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i=1; i<= race.numberOfLaps; i++) {
    race.currentLap++;
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}

int main() {
	srand(time(0));
  struct RaceCar raceCar1 = {"Carlos Sainz jr.","Ferrari", 0};
  struct RaceCar raceCar2 = {"Max Verstappen","Red Bull", 0};
  printIntro(); 
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};
