//convective diffusive transport equation

double time=0.0;
double final_time=10.0;
int time_steps=1000;
double dt=(final_time-time)/time_steps;

	const int partitionsX=100;
	const int partitionsY=100;
	double height=1.0;
	double width=1.0;
	double dx=height/partitionsX;
	double dy=width/partitionsY;
	
	double volume=dx*dy; //assuming 2d calculation, even if it has area dimensions is valid.
	double u[partitionsX][partitionsY],uo[partitionsX][partitionsY],u_estimated[partitionsX][partitionsY];
	
double dif(int i,int j,double u[partitionsX][partitionsY]){
	return (u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1])/4.0;}		
	
	//simplistic diffusion with dummy unitary constant coefficent
	
double error_eval(double u[partitionsX][partitionsY],double u_est[partitionsX][partitionsY]){
	double error=0.0;
	for (int i=1;i<partitionsX-1;i++) {
				for (int j=1;j<partitionsY-1;j++) {
					if(u[i][j]-u_est[i][j]<0){if(error<u_est[i][j]-u[i][j]){error=u_est[i][j]-u[i][j];}}
					else{if(error<u[i][j]-u_est[i][j]){u[i][j]-u_est[i][j];}};
				}
			}
	return error;
}
	
double conv(int i,int j){return 0.0;} //first without convection.



int main(){
	for (int j=0;j<partitionsY;j++) {u[0][j]=1.0;uo[0][j]=1.0;} //initial condition
	double error=1.0;
	while (time<final_time){
		while(error>0.00001){
			for (int i=1;i<partitionsX-1;i++) {
				for (int j=1;j<partitionsY-1;j++) {
			
					u[i][j]=uo[i][j]+dif(i,j,u_estimated)+conv(i,j);
				}
			}
			error=error_eval(u,u_estimated);
			for (int i=1;i<partitionsX-1;i++) {
			for (int j=1;j<partitionsY-1;j++) {u_estimated[i][j]=u[i][j];}}
			
		}
		time=time+dt;
		for (int i=1;i<partitionsX-1;i++) {
			for (int j=1;j<partitionsY-1;j++) {uo[i][j]=u[i][j];}}
		
	}
}
