#include "Korisnik.h"
#include <queue>
#include <stack>
#include "Hrana.h"
static queue<Korisnik> red;                //RED ZA KORISNIKE
static stack<Korisnik> kazan;              //STEK ZA KORISNIKA KOJI TRENUTNO BIRA HRANU
static queue<Supa> supe;                   
static queue<Hamburger> hamburgeri;
static queue<Salata> salate;
enum obroci{SUPA=1, HAMBURGER, SALATA};