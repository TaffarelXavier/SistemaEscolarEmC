#include <stdio.h>
#include <time.h> //Para poder trabalhar com datas.

//Quantidade máxima permitida de cursos:
#define MAX_QUANT_CURSOS 3

//Quantidade máxima permitida de Disciplinas:
#define MAX_QUANT_DISCIPLINAS 40

//Quantidade máxima permitida de Professores:
#define MAX_QUANT_PROFESSORES 10

//Quantidade máxima permitida de Alunos:
#define MAX_QUANT_ALUNOS 50

//Quantidade máxima permitida de Turmas:
#define MAX_QUANT_TURMAS 10
#define ICONE_1 "🎓"

/*contadores.
Serão usados para incremento, caso seja
incluído algum registro; decremento, caso
seja usado para excluir algum registro.
*/
int contAluno = 0, contProfessor = 0, contTurma = 0,
contDisciplina = 0, contCurso = 0;


//Serve para a limpar a tela do terminal. Aqui, para Linux.
//Quando for usar no Winodows, substituir por cls.;
#define clear() printf("\033[H\033[J")

//Para gráficos:
#define BARRA_SUPERIOR "╔══════════════════════════════════════════════╗"
#define BARRA_INFERIOR "╚══════════════════════════════════════════════╝"
#define BARRA_HORIZONTAL "════════════════════════════════════════════════"


//Imprime espaços
//O argumento é o total de espaços a ser impressos.
char prtEsp(int n){
    
    char espaco[n];

    for (int i = 0; i < n; i++)
    {
    espaco[i] = ' ';
    }
    
    return espaco;
}
/**
CURSOS
**/
typedef struct Curso {
    int curso_id;
    char titulo[128];
} Curso;

/**
Disciplina
**/
typedef struct Disciplina {
    int disc_id;
    char  titulo[128];
} Disciplina;

typedef struct Professor {
  int matricula;
  int cpf;
  char *nome;
  char *dataCriacao;
  int disciplina_fk_id;
} Professor;

/**
TURMA
**/
typedef struct Turma {
 int turma_id;
 int perido_letivo;
 char *sala;
 int professor_fk_id;
} Turma;

typedef struct Aluno {
   int id;
   int matricula;
   char nome[128];
   char *data_criacao;
   int curso_fk_id;
} Aluno;

void subMenu();

//Criação das instâncias das estruturas:
Curso cursos[MAX_QUANT_CURSOS];

Aluno alunos[MAX_QUANT_ALUNOS];

Professor professores[MAX_QUANT_PROFESSORES];

Turma turmas[MAX_QUANT_TURMAS];

Disciplina disciplina[MAX_QUANT_DISCIPLINAS];

//<!--FIM-->

//Métodos para os Curso:

void cadastrarCurso(){

    //Se a quantidade de cursos for menor
    //que a quantidade máxima de itens permitidos:
    if(contCurso < MAX_QUANT_CURSOS){

        printf("🎓  CRIAR NOVO CURSO: \n");

        printf("Nome do curso:");

        int n;

        n = scanf("%[^\n]s", cursos[contCurso].titulo);

        if(n>0){

            contCurso++;
            
            cursos[contCurso].curso_id = contCurso;

            printf("\nAluno cadastrado com sucesso!\n");
            
            clear();

            subMenu(1);
        }
    }
    else{
        printf("▛▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▜\n");
        printf("░ Máxima quantidade de cadastros permitidas.░\n");
        printf("▙▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▟\n");
    }
    
    
}
void editarCurso(){
    
}
void excluirCursor(){
    
}
void buscarCurso(){
    
}
void listarTodosCursos(){
     printf("%s\n",BARRA_SUPERIOR);

    if(contCurso == 0){
        printf("Não há cursos cadastrados.");
            }
            else{
        printf("🎓 LISTAGEM DE CURSOS:\n");

            for(int k = 0; k < contCurso; k++){
                printf("%d - %s\n",(cursos[k].curso_id + 1), cursos[k].titulo);
            }
            }
    
    printf("%s\n", BARRA_INFERIOR);
}

void cursosInit(int opt){
    clear();

    subMenu(opt);

    printf("%s\n", BARRA_HORIZONTAL);

    int op;

    printf("Digite um código:");

    do{
        scanf("%d", &op);

        if(op==1){
            clear();

            subMenu(opt);

            cadastrarCurso();
        }
        else if(op==2){

        }
        else if(op==5){
            listarTodosCursos();
        }
        
    }while(op != 6);

    clear();
}

/**
DISCIPLINAS
**/


void cadastrarDisciplina(){
    
}
void editarDisciplina(){
    
}
void excluirDisciplina(){
    
}
void buscarDisciplina(){
    
}
void listarTodosProfessor(){
    
}
//<!--Fim--->

/**
PROFESSOR
**/
//Métodos para os Professores:
void cadastrarProfessor(){
    
}
void editarProfessor(){
    
}
void excluirProfessor(){
    
}
void buscarProfessor(){
    
}
void listarTodosProfessores(){
    
}
//<!--Fim--->

//Métodos para os Turma:
void cadastrarTurma(){
    
}
void editarTurma(){
    
}
void excluirTurma(){
    
}
void buscarTurma(){
    
}
void listarTodasTurmas(){
    
}
//<!--Fim--->

/**
ALUNO
**/

//Métodos para os Alunos:
//Fonte: http://www.cplusplus.com/reference/ctime/strftime/
void obterDataAtual(){
    //Cria uma nova instância da struct time_t
  time_t rawtime;

  struct tm * timeinfo;

  char buffer[80];

  time (&rawtime);

  timeinfo = localtime (&rawtime);

  strftime(buffer,80,"%d-%m-%Y",timeinfo);

 printf("%s",buffer);
}

void cadastrarAluno(){

    printf("🎓  CADASTRO DO ALUNO %s a\n", prtEsp(5));

    printf("Digite o nome do aluno:");
    
    int n;

    n = scanf("%[^\n]s", alunos[contAluno].nome);
    
    if(n>0){

        contAluno++;
        
        alunos[contAluno].id = contAluno;
        
        printf("%d", alunos[contAluno].id );

        clear();
    }
    
   
}
void editarAluno(){
    
}
void excluirAluno(){
    
}
void buscarAluno(){
    
}

void listarTodosAlunos(){
    printf("%s\n",BARRA_SUPERIOR);
    clear();

    if(contAluno  == 0){
        subMenu(5);
        
        printf("║ Não há nenhum aluno cadastrado.              ║\n");
    }else{

        printf("\n🎓 LISTAGEM DE ALUNOS:\n");

        for(int k = 0; k < contAluno; k++){
        printf("%d - %s\n",(alunos[k].id + 1), alunos[k].nome);
        }

        
    }
    printf("%s\n", BARRA_INFERIOR);

}
void fazerMatricula(){
    
}
//<!--Fim--->

//Métodos para os Disciplina:
void subMenu(opcao){
    clear();
    printf("%s\n",BARRA_SUPERIOR);
    if(opcao==1){
        printf("║ 🎓  CURSO - ESCOLHA UMA OPÇÃO:                ║\n"); 
    }else if(opcao==2){
        printf("║ 🎓  DISCIPLINA - ESCOLHA UMA OPÇÃO:           ║\n"); 
    }else if(opcao==3){
        printf("║ 🎓  PROFESSOR - ESCOLHA UMA OPÇÃO:            ║\n"); 
    }else if(opcao==4){
        printf("║ 🎓  TURMA - ESCOLHA UMA OPÇÃO:                ║\n"); 
    }else if(opcao==5){
        printf("║ 🎓  ALUNO - ESCOLHA UMA OPÇÃO:                ║\n"); 
    } 
    printf("║ 1 - Criar                                    ║\n");
    printf("║ 2 - Editar                                   ║\n");
    printf("║ 3 - Excluir                                  ║\n");
    printf("║ 4 - Buscar                                   ║\n");
    printf("║ 5 - Listar Todas                             ║ \n");
    printf("║ 6 - Voltar ao MENU Inicial                   ║ \n");
    printf("%s\n", BARRA_INFERIOR);
}
/**
Este subMenu mostrará as opções para opções
o usuário:
*/
void menuPrincipal(){
    clear();
    printf("%s\n",BARRA_SUPERIOR);
    printf("║               🎓  SISTEMA ESCOLAR             ║\n");   
    printf("%s\n", BARRA_INFERIOR);
    printf("%s\n",BARRA_SUPERIOR);
    printf("║ 🎓  MENU PRINCIPAL - ESCOLHA UMA OPÇÃO:       ║\n");   
    printf("║ 1 - Curso                                    ║\n");
    printf("║ 2 - Disciplina                               ║\n");
    printf("║ 3 - Professor                                ║\n");
    printf("║ 4 - Turma                                    ║\n");
    printf("║ 5 - Aluno                                    ║ \n");
    printf("║ 6 - Sair                                     ║ \n");
    printf("%s\n", BARRA_INFERIOR);
    printf("☞ ::");

}

void iniciar(){
     int opt;
     menuPrincipal();
    do{

    scanf("%d", &opt);

   switch(opt){
    case 1: //Trabalhar com Curso
       cursosInit(opt);
    break;
    case 2: //Trabalhar com Disciplina
        subMenu(opt);
    break;
    case 3: //Trabalhar com Professor
        subMenu(opt);
    break;
    case 4: //Trabalhar com Turma
        subMenu(opt);
    break;
    case 5: //Trabalhar com Aluno

        clear();

        subMenu(opt);
   
        printf("%s\n", BARRA_HORIZONTAL);

        int op;
        
        printf("Digite um código:");

        do{
            scanf("%d", &op);
            if(op==1){
                cadastrarAluno();
            }
            else if(op==5){
                listarTodosAlunos();
            }
            
        }while(op != 6);
        
     clear();
    break;
    case 6: //Menu principal
         menuPrincipal();
    break;
    default:
     printf("Tese");
    break;
   }

    }
    while(opt!=-1);
}
//<!--Fim--->

int main(void) {
   iniciar();
 /* Professor professor;
    professor.nome = "Taffarel";
    printf("%s",professor.nome );*/

  return 0;
}
