#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int graph[7][7];
bool ziyaret[7];

void matrisoku(){
	
    int i = 0;
    FILE *fp = fopen("dfs.txt", "r");
 
    while(fscanf(fp, "%d %d %d %d %d %d %d",
                 &graph[i][0],
                 &graph[i][1],
                 &graph[i][2],
                 &graph[i][3],
                 &graph[i][4],
                 &graph[i][5],
                   &graph[i][6]
                 ) != EOF){
        i = i + 1 ;
    }
}


void DFS(int root, bool ziyaret[]){
	int i;
	ziyaret[root] = true;//ilk aþamada rootu ziyaret edildi olarak atadýk
	printf("%d ",root);
	for(i = 1; i < 8; i++){
		if(graph[root][i] == 1 && ziyaret[i] == false ){//matrisler arasý baðlantý varsa ve matris ziyaret edilmemiþse
			DFS(i, ziyaret);
		}
	}
}

int main(){
	matrisoku();
	printf("DFS Algoritmasi\n");
	DFS(1, ziyaret);
	getch();
}
