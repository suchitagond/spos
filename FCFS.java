import java.util.*;

class FCFS{
    public static void main(String [] args){
        Scanner s=new Scanner(System.in);
        System.out.print("Enter no of process you have : ");
        int n=s.nextInt();
        
        String proc[]=new String[n];
        int AT[]=new int[n];
        int BT[]=new int[n];
        int CT[]=new int[n];
        int WT[]=new int[n];
        int TAT[]=new int[n];
        
        for(int i=0;i<n;i++){
            System.out.print("Enter process name for "+(i+1)+" process : ");
            proc[i]=s.next();
            System.out.print("Enter arrival time for "+proc[i]+" process : ");
            AT[i]=s.nextInt();
            System.out.print("Enter Burst time for "+proc[i]+" process : ");
            BT[i]=s.nextInt();
            System.out.println();
            //proc[i]=i+1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n-(i+1);j++){
                if(AT[j]>AT[j+1]){
                    int temp=AT[j];
                    AT[j]=AT[j+1];
                    AT[j+1]=temp;
                    
                    temp=BT[j];
                    BT[j]=BT[j+1];
                    BT[j+1]=temp;
                    
                    String temp1=proc[j];
                    proc[j]=proc[j+1];
                    proc[j+1]=temp1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(i==0){
                CT[i]=AT[i]+BT[i];
            }
            else{
                if(AT[i]>CT[i-1]){
                    CT[i]=AT[i]+BT[i];
                }
                else{
                    CT[i]=CT[i-1]+BT[i];
                }
            }
            TAT[i]=CT[i]-AT[i];
            WT[i]=TAT[i]-BT[i];
        }
        
        System.out.println("Process\tArrival_Time\tBrust_Time\tComplete_Time\tTurn_arround\tWaiting_Time");
        
        for(int i=0;i<n;i++){
            System.out.println(proc[i]+"\t\t"+AT[i]+"\t\t"+BT[i]+"\t\t"+CT[i]+"\t\t"+TAT[i]+"\t\t"+WT[i]);
        }      
  
    }
}
