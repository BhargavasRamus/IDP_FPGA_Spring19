module mat_mul(input [7:0] A, 
				input clk,
				input reset,
				output reg [7:0] P,
				output reg test,
        output reg test1,
				input resOut
				);
	integer counter,iter1,iter2,flag,flag1,flagO,flagO2,flagO3,Pi,Pj,t;
	integer i,j,k,I,J,temp,flagO1,iterb1,iterb2,count,temp1,i1,j1,flagO4;
	parameter n =3;
	reg [7:0] memA [0:n-1][0:n-1];
	reg [7:0] memB [0:n-1][0:n-1];
	reg [15:0] memC [0:n-1][0:n-1];
	reg [15:0] T;

	
	initial begin
		t = 0;
		I = 0;
		i=0;
		j=0;
		i1=0;
		j1=0;
		J = 0;
		Pi = 0;
		Pj = 0;
		temp = 0;
		temp1 = 0;
		flag = 0;
		flag1 = 0;
		flagO = 0;
		flagO1 = 0;
		flagO2 = 0;
		flagO3 = 0;
		flagO4 = 0;
		iter1 = 0;
		iter2 = 0;
		iterb1 = 0;
		iterb2 = 0;
		counter = 0;
		count = 0;
		T = 0;
		memC[0][0] = 0;
		test = 1'b0;
	end
	always @(posedge reset) begin
		if (flag == 0 && flag1 == 0) begin
			memA [iter1][iter2] = A;
			iter2 = iter2+1;
			if(iter2 == n) begin
				iter2 = 0;
				iter1 = iter1 + 1;
				if (iter1 == n) begin
					iter1 = 0;
					flag1 = 1;
					
				end
			end
		end
		if (flag1==1 && counter == 0 && temp==1 ) begin
			memB [iterb1][iterb2] = A;
			iterb2 = iterb2+1;
			if (iterb2 == n) begin
				iterb2 = 0;
				iterb1 = iterb1 + 1;
				if (iterb1 == n) begin
					iterb1 = 0;
					flagO1 = 1;
					counter = 1;
					test = 1'b1;
				end
			end
		end
		if(flag1==1) begin
			temp = 1;
		end
		/*if(flagO1==1) begin
			test = 1'b1;
		end*/
	end
	always @(posedge resOut) begin
		/*if (flagO1==1 && flagO==0) begin
			P = memA[Pi][Pj];
			Pj = Pj+1;
			if(Pj==n)begin
				Pj = 0;
				Pi = Pi+1;
				if (Pi == n) begin
					Pi = 0;
					flagO = 1;
				end
			end
		end*/
                
		/*if (flagO==1 && flagO2==0 && temp1==1) begin
			P = memB[I][J];
			J = J+1;
			if(J==n)begin
				J = 0;
				I = I+1;
				if (I == n) begin
					I = 0;
					flagO2 = 1;
					
				end
			end
		end*/

		/*if(flagO==1) begin
			temp1 = 1;
		end*/
		if( flagO1==1 && flagO3==0) begin
			memC[i][j] = memA[i][t]*memB[t][j]+memC[i][j];
  			t = t+1;
			if(t==n) begin
				t = 0;
				j = j+1;
				if(j==n) begin
					j=0;
					i = i+1;
					if(i == n) begin
						flagO3 =1;
            test1 = 1'b1;
					end
				end
				if(i<n) begin
					memC[i][j] = 0;
				end
			end
		end
		if(flagO3==1 && flagO4==0) begin
			if (count%2==0) begin
				P = memC[i1][j1][15:8];
			end
			else begin
				P = memC[i1][j1][7:0];
				j1 = j1+1;
				if(j1==n) begin
					j1=0;
					i1=i1+1;
					if(i1==n) begin
						i1=0;
						flagO4 = 1;
					end
				end
					
			end
			count = count + 1;
		end
	end
endmodule
