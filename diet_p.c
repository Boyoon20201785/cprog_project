#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
int cnt = 0;
int score_tot = 0;
typedef struct fnode{
    char fname[SIZE];    //음식 이름
    int score;    //건강도 점수
    struct node* next;
}node_f;

void check_success(int score_tot, FILE* fp, int cnt){         //성공여부 출력후 결과를 날짜 및 성공여부로 저장 (날짜 : **.**/ 성공여부 : p or f)

    float day;            //   날짜를 저장 ex -> 12.12
		int ck;

    if ((500<score_tot)&&(cnt<10)){    //성공 조건
     		printf("오늘은 성공입니다.\n");
				ck = 1;
    }else{
        printf("오늘은 실패입니다.\n");
				ck = 0;
    }
    printf("날짜를 입력하시오.(**.** 형태)");
    scanf("%f", &day);
    fp = fopen("data.txt", "w");
    if (fp = NULL){
        printf("cannot find file\n");
    }
    else{
				if(ck == 1)
        	fprintf(fp, "%.2f pass", day);
				else
					fprintf(fp, "%.2f fail", day);
    }
    fclose(fp);
}


void add_node(int n){     //음식 노드를 내림차순으로 추가(+ 점수를 미리 더해 놓음-----score_tot)
    int k=0;
    node_f* new_node;
    node_f* list_head = NULL;
    node_f* next_p;
    node_f* prev_p;
    if (n==1)
        while(k==-1){
            new_node = (node_f*)malloc(sizeof(node_f));
            printf("음식 이름과 점수를 입력: ");
            scanf("%s %d", new_node->fname, &new_node->score);
            printf("%s이(가) %d점으로 추가 되었습니다.\n", new_node->fname, new_node->score);

            next_p = list_head;
            prev_p = NULL;
            while (next_p){
                if (next_p->score < new_node->score)
                    break;
                prev_p = next_p;
                next_p = next_p->next;
            }

            if (prev_p){
                prev_p->next = new_node;
            }
            else{
                list_head = new_node;
            }
            cnt++;
            score_tot += new_node->score;
            printf("먹은 음식 추가를 중단하려면 -1을 입력하세요.\n");
            scanf("%d", &k);
        }
    if (n==3){
        
    }
}
  

void file_load(FILE* fp){
    int ps;
    int fs;
    float day;
    char cpf[SIZE];
    int cntd;

    fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("Error");
    }else{
        while(!feof(fp)){
            fscanf("%f %s", &day, cpf);
            cntd++;
            if (cpf=="pass"){
                ps++;
            }else{
                fs++;
            }
        }
    }
    printf("지난 %d일 동안 성공 %d번, 실패 %d번을 경험했습니다.\n", cntd, ps, fs);
}



int main()
{
    int n;
    FILE *fp;


    do{
    printf("=====================================\n");
    printf("메뉴를 입력\n1.새로운 음식 추가\n2. 오늘 먹은 음식 평가하기\n3. 오늘 먹은 음식 중 점수가 높은 것과 낮은 것 출력\n");
    printf("4. 지난 날의 성공과 실패 횟수 보기\n5. 종료");
    printf("=====================================\n");
    scanf("%d", &n);

    if (n==1){
        add_node(n);
    }
    if (n==2){
        check_success(score_tot, fp, cnt);
        }
    
    if (n==3){
        
        //printf("오늘 음식 중 점수가 가장 높은 것은 %s, 가장 낮은 것은 %s입니다.", highf, lowf);
    }
    if (n==4){
        file_load(fp);
    }

    }while (n==5);
    //free(new_node);
    return 0;
}
