#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    int id;
    char name[100];
    char writer[100];
    float cost;
};
int main() {
    FILE *f, *temp;
    struct Book bk;
    int ch, bid, found=0;
    while(1) {
        printf("\n==== Library Menu ====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d",&ch);
        if(ch==1) {
            f = fopen("books.dat","ab");
            if(f==NULL){ printf("File error"); exit(1); }
            printf("Enter id: ");
            scanf("%d",&bk.id);
            getchar();
            printf("Enter name: ");
            fgets(bk.name,100,stdin);
            bk.name[strcspn(bk.name,"\n")] = 0;
            printf("Enter writer: ");
            fgets(bk.writer,100,stdin);
            bk.writer[strcspn(bk.writer,"\n")] = 0;
            printf("Enter cost: ");
            scanf("%f",&bk.cost);
            fwrite(&bk,sizeof(bk),1,f);
            fclose(f);
            printf("Saved.\n");
        }else if(ch==2) {
            f = fopen("books.dat","rb");
            if(!f) {
                printf("No data.\n");
                continue;
            }
            while(fread(&bk,sizeof(bk),1,f)) {
                printf("\nID: %d\n", bk.id);
                printf("Name: %s\n", bk.name);
                printf("Writer: %s\n", bk.writer);
                printf("Cost: %.2f\n", bk.cost);
            }
            fclose(f);
        }
        else if(ch==3) {
            printf("Enter id: ");
            scanf("%d",&bid);
            f = fopen("books.dat","rb");
            if(!f){ printf("No file.\n"); continue; }
            found = 0;
            while(fread(&bk,sizeof(bk),1,f)) {
                if(bk.id==bid) {
                    printf("Found:\n");
                    printf("Name: %s\n", bk.name);
                    printf("Writer: %s\n", bk.writer);
                    printf("Cost: %.2f\n", bk.cost);
                    found = 1;
                    break;
                }
            }
            fclose(f);
if(!found) printf("Not found.\n");
        }
        else if(ch==4) {
            printf("Enter id to update: ");
            scanf("%d",&bid);
            getchar();
            f = fopen("books.dat","rb+");
            if(!f){ printf("No file.\n"); continue; }
            found=0;
            while(fread(&bk,sizeof(bk),1,f)) {
                if(bk.id==bid) {
                    printf("New name: ");
                    fgets(bk.name,100,stdin);
                    bk.name[strcspn(bk.name,"\n")] = 0;
                    printf("New writer: ");
                    fgets(bk.writer,100,stdin);
                    bk.writer[strcspn(bk.writer,"\n")] = 0;
                    printf("New cost: ");
                    scanf("%f",&bk.cost);
                    fseek(f, -sizeof(bk), SEEK_CUR);
                    fwrite(&bk,sizeof(bk),1,f);
                    found = 1;
                    printf("Updated.\n");
                    break;
                }
            }
            fclose(f);
            if(!found) printf("ID not found.\n");
        }
        else if(ch==5) {
            printf("Enter id to delete: ");
            scanf("%d",&bid);
            f = fopen("books.dat","rb");
            if(!f){ printf("No file.\n"); continue; }
            temp = fopen("temp.dat","wb");
            found=0;
            while(fread(&bk,sizeof(bk),1,f)) {
                if(bk.id != bid) {
                    fwrite(&bk,sizeof(bk),1,temp);
                } else {
                    found=1;
                }
            }
            fclose(f);
            fclose(temp);
            remove("books.dat");
            rename("temp.dat","books.dat");
            if(found) printf("Deleted.\n");
            else printf("ID not found.\n");
        }
        else if(ch==6) {
            break;
        }
        else {
            printf("Invalid.\n");
        }
    }
    return 0;
}
