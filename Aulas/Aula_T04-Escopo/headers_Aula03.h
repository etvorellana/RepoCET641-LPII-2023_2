

int horas, minutos, segundos;  // variáveis globais
struct horario
{
    int horas;
    int minutos;
    int segundos;
};

typedef struct horario Horario;

// protótipos das funções

int ajustaFgetsString(char string[]);
void embaralhaString(char string[]);

void seg2hms(int tempo);
int hms2seg(int horas, int minutos, int segundos);

Horario seg2hms_(int tempo);
int hms2seg_(Horario horario);

void codificaString(char string[]);
void codificaMsg(char string[], char msg[]);
int tokensIguais(char nome1[], char nome2[], int N);

