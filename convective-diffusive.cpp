//convective diffusive transport equation

double dif(int i,int j){return 0.0;}
double conv(int i,int j){return 0.0;}

int main(){
	int sizeX=100;
	int sizeY=100;
	double u[][],u[][];
	for (int i=0;i<sizeX;i++) {
		for (int j=0;j<sizeY;j++) {
	
			u[i][j]=uo[i][j]+dif(neighbours(i,j))+conv(neighbours(i,j));
	}
}
}
