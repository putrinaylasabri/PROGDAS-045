#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return -1; // Unable to determine console width
}

int diceRoll(){
	
	return (rand() % 20) + 1;
	
}

// Struktur data untuk serangan musuh
struct EnemyAttack {
    char name[50];
    int damage;
    int staminaCost;
};

// Fungsi untuk memilih serangan musuh secara acak
int chooseRandomAttack(struct EnemyAttack *attacks, int numAttacks) {
    return rand() % numAttacks;
}

// Inisialisasi serangan musuh
void initEnemyAttacks(struct EnemyAttack *attacks, int numAttacks) {
    strcpy(attacks[0].name, "Normal Attack");
    attacks[0].damage = 15;
    attacks[0].staminaCost = 10;

    strcpy(attacks[1].name, "Heavy Attack");
    attacks[1].damage = 20;
    attacks[1].staminaCost = 15;

    strcpy(attacks[2].name, "Ultimate");
    attacks[2].damage = 30;
    attacks[2].staminaCost = 25;

    // Tambahkan serangan musuh lain jika diperlukan
}

int enemyRollDice(int sides) {
    return rand() % sides + 1;
}

struct Enemy {
    int hp;     
    int stm;    
    int diceSides; 
    int attack;
    int damage;
};

void initEnemy(struct Enemy *enemy, int initialHP, int initialSTM, int diceSides, int initialAttack) {
    enemy->hp = initialHP;
    enemy->stm = initialSTM;
    enemy->diceSides = diceSides;
    enemy->attack = initialAttack;
}

int calculateEnemyDamage(struct Enemy *enemy, int diceRoll) {
    int damage = diceRoll + enemy->attack - 5;
    enemy->stm -= 20;
    return damage;
}

void displayEnemyStatusAndDamage(struct Enemy *enemy) {
	int diceRoll = enemyRollDice(enemy->diceSides);
    printf("\n\nStatus Musuh:\n\nMusuh melempar dadu!!\n");
    //printf("Current HP: %d\n", enemy->hp);
    //printf("Current STM: %d\n", enemy->stm);
    Sleep(2000);
    printf("Hasil lemparan dadu: %d\n", diceRoll);

    // Menghitung dan mencetak damage yang dihasilkan oleh musuh
    int damage = calculateEnemyDamage(enemy,diceRoll);
    printf("Damage yang dihasilkan oleh musuh: %d\n", damage);
    enemy->damage = damage;

}

int damageCalculation(int baseDamage, int diceRoll){
	
	int result = baseDamage + diceRoll - 5;
	
	return result;
}

int hpCalculation(int HP, int damageTaken){
	
	int result = HP - damageTaken;
	
	return result;
	
}

int normalAttack(float baseDamage, float diceRoll) {
	return baseDamage + diceRoll - 5;
}

int heavyAttack(float baseDamage, float diceRoll) {
    return baseDamage + diceRoll; 
}

int ultimateAttack(float baseDamage, float diceRoll) {
    return baseDamage + diceRoll + 5; // Contoh: ultimate attack dapat menyebabkan lima kali lipat damage
}

void drawHealthBar(int currentHP, int maxHP, int barWidth) {
    int barLength = (int)((float)currentHP / maxHP * barWidth);
	int i;
	
    printf("HP:		[");
    
    for (i = 0; i < barWidth; i++) {
        if (i < barLength) {
            printf("\033[1;32m#\033[0m");
        } else {
            printf(" ");
        }
    }
    
    printf("] %d/%d", currentHP, maxHP);
}

void drawStaminaBar(int currentStamina, int maxStamina, int barWidth) {
    int barLength = (int)((float)currentStamina / maxStamina * barWidth);
	int i;
	
    printf("Stamina:	[");

    for (i = 0; i < barWidth; i++) {
        if (i < barLength) {
            printf("\033[1;33m#\033[0m");
        } else {
            printf(" ");
        }
    }

    printf("] %d/%d", currentStamina, maxStamina);
}

void drawEnemyHealthBar(int currentHP, int maxHP, int barWidth) {
    int barLength = (int)((float)currentHP / maxHP * barWidth);
	int i;
	
    printf("ENEMY:		[");
    
    for (i = 0; i < barWidth; i++) {
        if (i < barLength) {
            printf("\033[1;31m#\033[0m");
        } else {
            printf(" ");
        }
    }
    
    printf("] %d/%d\n", currentHP, maxHP);
}

void drawEnemyStaminaBar(int currentStamina, int maxStamina, int barWidth) {
    int barLength = (int)((float)currentStamina / maxStamina * barWidth);
    int i;
    
    printf("ENEMY STAMINA:  [");
    
    for (i = 0; i < barWidth; i++) {
        if (i < barLength) {
            printf("\033[1;34m#\033[0m");
        } else {
            printf(" ");
        }
    }
    
    printf("] %d/%d\n", currentStamina, maxStamina);
}

int main(){
	
	keybd_event(VK_MENU, 0x38, 0, 0); // Menekan tombol Alt
    keybd_event(VK_RETURN, 0x1c, 0, 0); // Menekan tombol Enter
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Melepaskan tombol Enter
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); // Melepaskan tombol Alt
	
	
	srand(time(NULL));
	struct Enemy enemy;
	const int totalHp = 200;
	const int barWidth = 20;
	const int totalStm = 100;
	int baseHp = 200;
	int baseHpPlayer = 200;
	int baseStm = 100; // error di stamina
	int baseDamage = 10;
	int resultDice;
	int choice;
	int attackChoice;
	int i;
	int panjang = getConsoleWidth();
	int padding = panjang - 62;
	initEnemy(&enemy, 100, 100, 20, 10);
	
	struct EnemyAttack enemyAttacks[3]; // Jumlah serangan musuh
    initEnemyAttacks(enemyAttacks, 3);
	
		while(1){
			
			system("cls");
			
    		if (baseHpPlayer <= 0 && baseHp <= 0) {
            	printf("SERIIII!!!\n");
            	break; // Keluar dari loop jika pemain kalah.
        	}
    		
			if (baseHpPlayer <= 0 && baseHp > 0) {
            	printf("Kamu kalah!\n");
            	break; // Keluar dari loop jika pemain kalah.
        	}
        	
        	if (baseHp <= 0 && baseHpPlayer > 0) {
            	printf("Kamu menang!\n");
            	break; // Keluar dari loop jika pemain menang.
        	}
			
			drawHealthBar(baseHpPlayer, totalHp, barWidth);
			
			Sleep(100);
			for(i = 1;i <=  padding;i++){
				printf(" ");
			}
			
			drawEnemyHealthBar(baseHp, totalHp, barWidth);
			drawStaminaBar(baseStm, totalStm, barWidth);
			
			Sleep(100);
			for(i = 1;i <=  padding;i++){
				printf(" ");
			}
			
			drawEnemyStaminaBar(enemy.stm, totalStm, barWidth);
			
			if(baseStm <= 0){
				printf("kamu kehabisan energy harus istirahat!!");
				baseStm += 20;
				
				if(enemy.stm <= 0){
					enemy.stm += 20;
					printf("\n musuh sedang istirahat untuk memulihkan stamina");
					continue;
				}
				
				displayEnemyStatusAndDamage(&enemy);
				
				int taken = baseHpPlayer - enemy.damage;
				baseHpPlayer = taken;		
				
				Sleep(3000);
				continue;
			}
			
			//printf("\nHP musuh sekarang : %d\n\n", baseHp);
			//printf("HP anda sekarang : %d\n", baseHpPlayer);
			//printf("Stamina anda sekarang : %d\n\n", baseStm);
			
			printf("your turn:\n1.attack\n2.take rest\nchose wisely my mere human 1/2 : ");
			scanf("%d", &choice);
			
			if(choice == 1){
				printf("\nyou are attacking!!\n\npick type of attack:\n\n");
		
				printf("1.normal attack\n2.heavy attack\n3.ultimate\n\nusing attack number : ");
				scanf("%d", &attackChoice);
				
				if(attackChoice == 1){
				   	printf("\nyou attacking with normal attack\nroll dice press y!!");
				   	char input;
				   	scanf(" %c", &input);
				   	
					if (input == 'y' || input == 'Y'){
						resultDice = diceRoll();
	       				printf("dice number: %d\n", resultDice);
	       				
	       				int damage = normalAttack(baseDamage, resultDice);
	       				int HP = hpCalculation(baseHp, damage);
	       				baseHp = HP;
	       				int Stm = baseStm - 10;
	       				baseStm = Stm;
	       				printf("damage deal to enemy :%d\n", damage);
	       				
	       				if(enemy.stm <= 0){
							   enemy.stm += 20;
							   printf("\n musuh sedang istirahat untuk memulihkan stamina");
							   continue;
						}
	       				
	       				displayEnemyStatusAndDamage(&enemy);
	       				
	       				int taken = baseHpPlayer - enemy.damage;
			   			baseHpPlayer = taken;
						
					}
				}
				else if(attackChoice == 2){
					printf("\nyou attacking with heavy attack\nroll dice press y!!");
					char input;
					scanf(" %c", &input);
					if (input == 'y' || input == 'Y'){
						resultDice = diceRoll();
	       				printf("dice number: %d\n", resultDice);
	       				
	       				int damage = heavyAttack(baseDamage, resultDice);
	       				int HP = hpCalculation(baseHp, damage);
	       				baseHp = HP;
	       				int Stm = baseStm - 20;
	       				baseStm = Stm;
	       				printf("damage deal to enemy :%d\n", damage);
	       				
	       				if(enemy.stm <= 0){
							   enemy.stm += 20;
							   printf("\n musuh sedang istirahat untuk memulihkan stamina");
							   continue;
						}
	       				
	       				displayEnemyStatusAndDamage(&enemy);
	       				
	       				int taken = baseHpPlayer - enemy.damage;
			   			baseHpPlayer = taken;
	       				
					}
				}
				else if(attackChoice == 3){
					printf("\nyou attacking with ultimate\nroll dice press y!!");
					char input;
					scanf(" %c", &input);
					if (input == 'y' || input == 'Y'){
						resultDice = diceRoll();
	       				printf("dice number: %d\n", resultDice);
	       				
	       				int damage = ultimateAttack(baseDamage, resultDice);
	       				int HP = hpCalculation(baseHp, damage);
	       				baseHp = HP;
	       				int Stm = baseStm - 30;
	       				baseStm = Stm;
	       				printf("damage deal to enemy :%d\n", damage);
	       				
	       				if(enemy.stm <= 0){
							   enemy.stm += 20;
							   printf("\n musuh sedang istirahat untuk memulihkan stamina");
							   continue;
						}
	       				
			   			displayEnemyStatusAndDamage(&enemy);
	       				
	       				int taken = baseHpPlayer - enemy.damage;
			   			baseHpPlayer = taken;
	       				
					}
				} 
				else {
			   		printf("not an option");
				}
				
				// Pemilihan serangan musuh
   	   	   	  int enemyAttackIndex = chooseRandomAttack(enemyAttacks, 3);
 			  struct EnemyAttack enemyAttack = enemyAttacks[enemyAttackIndex];
 			  int damage = diceRoll + enemyAttack.damage - 5;
			  baseStm -= enemyAttack.staminaCost;

   	   	      printf("Musuh menggunakan %s dengan kerusakan %d\n", enemyAttack.name, enemyAttack.damage);
				
			} else if(choice == 2){
			   	printf("kamu sedang istirahat");
			   	baseStm += 20;
			   	
			   	if(enemy.stm <= 0){
					enemy.stm += 20;
					printf("\n musuh sedang istirahat untuk memulihkan stamina");
					continue;
				}
			   	
			   	displayEnemyStatusAndDamage(&enemy);
			   	
			   	int taken = baseHpPlayer - enemy.damage;
			   	baseHpPlayer = taken;
			} 
			else{
			   	printf("not an option");
			}
			
			
 			Sleep(4000);
		}
		
	return 0;
	
}