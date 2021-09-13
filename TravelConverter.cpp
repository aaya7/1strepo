#include <stdio.h>
#include <conio.h>
#include <math.h>

struct customer{
	char custName [25];
	char custID[25];
	char place;
	float convert;
} customer;

float calcAvg( float totalconv, int size);
float calcDollar(float convert);
float calcPound(float convert);
float calcEuro(float convert);
float calcProfDollar(float rmDollar);
float calcProfPound(float rmPound);
float calcProfEuro(float rmEuro);
void displayinfo (struct customer customer);
int countCust(char place, int count);

int main () {
	printf("\t--------------------------------------------------\n");
	printf("\t\tWELCOME TO TRAVEL CONVERTER SYSTEM\n");
	printf("\t--------------------------------------------------\n");
	
	float rmPound, rmDollar, rmEuro, average;
	float profitDollar, profitPound, profitEuro;
	int size;
	float totalconv =0;

		printf("\n\tEnter the number of conversion \n\tthat you want to proceed: ");
		scanf("%d", &size);
		struct customer customer[size];
	
		for (int i=0;i<size;i++){
			
			printf("\n\tEnter Name: ");
			scanf(" %s",&customer[i].custName);
			printf("\tEnter ID: ");
			scanf(" %s",&customer[i].custID);
			printf("\tChoose Place [F = France | G - Germany | B = Britain | \n\tT = Tristan de Cunha | U = United States | E = Ecuador]: ");
			scanf(" %c", &customer[i].place);
			printf("\tEnter Amount to Convert: RM");
			scanf(" %f",&customer[i].convert);
			
			if(customer[i].place == 'B' || customer[i].place == 'T' ){
		
				rmPound = calcPound (customer[i].convert);
				printf("\n\tYour money will be converted to Pound");
				printf("\n\tRM to Pound= %.2f", rmPound);
				if (rmPound > 1000){
					profitPound = calcProfPound(rmPound);
					printf("\n\tProfit recieved is RM %.2f", profitPound);
					}
				printf("\n\n*\t*\t*\t*\t*\t*\t*\n");
				
			}
			else if(customer[i].place == 'F' || customer[i].place == 'G' ){
			
				rmEuro = calcEuro (customer[i].convert);
				printf("\n\tYour money will be converted to Euro");
				printf("\n\tRM to Euro= %.2f", rmEuro);
				if (rmEuro > 1000){
					profitEuro = calcProfEuro(rmEuro);
					printf("\n\tProfit recieved is RM %.2f", profitEuro);
					}
				printf("\n\n*\t*\t*\t*\t*\t*\t*\n");
					
			}
			else if(customer[i].place == 'U' || customer[i].place == 'E' ){
				
				rmDollar = calcDollar (customer[i].convert);
				printf("\n\tYour money will be converted to Dollar");
				printf("\n\tRM to Dollar= %.2f", rmDollar);
				if (rmDollar > 1000){
					profitDollar = calcProfDollar(rmDollar);
					printf("\n\tProfit recieved is RM %.2f", profitDollar);
					}
				printf("\n\n*\t*\t*\t*\t*\t*\t*\n");
			}
			else
				printf("\n\tMoney Convertion is failed");
				
	}	
		printf("\n\tCustomer Information Display\n");
		
		for (int i=0;i<size;i++){
			displayinfo(customer[i]);
			totalconv = totalconv + customer[i].convert;
			average = calcAvg(totalconv, size);
		}
		printf("\n\n\tConverted Amount: RM %.2f", totalconv);
		printf("\n\tAverage of the conversion process is: RM = %.2f", average);
		
		int count=0;
		for (int i=0;i<size;i++){
			count = countCust(customer[i].place, count);
		}
		printf("\n\tTotal customer that are going to France is: %d", count);
		
		return 0;
		
}

float calcDollar(float convert){
	float rmDollar = convert/ 4.17;
	return rmDollar;
}
float calcPound(float convert){
	float rmPound = convert/5.70;
	return rmPound;
}
float calcEuro(float convert){
	float rmEuro = convert/5.80;
	return rmEuro;
}
float calcAvg( float totalconv, int size){
	float average = totalconv/size;
	return average;
}
float calcProfDollar(float rmDollar) {
	float profitDollar = (rmDollar*0.07);
	return profitDollar;
}
float calcProfPound(float rmPound) {
	float profitPound = (rmPound*0.03);
	return profitPound;
}
float calcProfEuro(float rmEuro) {
	float profitEuro = (rmEuro*0.05);
	return profitEuro;
}

void displayinfo (struct customer customer){
	printf("\n\tCustomer Name: %s", customer.custName);
	printf("\n\tCustomer ID: %s", customer.custID);
	printf("\n\tPlace Chosen: %c", customer.place);
	if (customer.place == 'F'){
		printf("\n\tCustomer is going to France");
	}
	else if(customer.place == 'G'){
		printf("\n\tCustomer is going to Germany");
	}
	else if(customer.place == 'B'){
		printf("\n\tCustomer is going to Britain");
	}
	else if(customer.place == 'T'){
		printf("\n\tCustomer is going to Tristan De Cunha");
	}
	else if(customer.place == 'U'){
		printf("\n\tCustomer is going to United States");
	}
	else if(customer.place == 'E'){
		printf("\n\tCustomer is going to Ecuador");
	}
	else {
		printf("\n\tPlace is not available for money conversion");
	}
	printf("\n\tRinggit Malaysia to convert:%.2f \n", customer.convert);
}
int countCust(char place, int count){
	if (place == 'F'){
		count++;
	}		
	return count;
}

		
	



