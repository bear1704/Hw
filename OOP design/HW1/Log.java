package new_pos;


//
//20133222 박수찬
//포스기의 Log 기록을 담당합니다

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;
public class Log implements Serializable{

	ArrayList<String> log = new ArrayList<>();
	static Scanner sc = new Scanner(System.in);
	
	
	public void welcome(Worker w){
		System.out.println("---------로그 열람 기능입니다.-----");
		
		if(w.getAdmin()){
		showLog();}
		else{
			System.out.println("권한이 없습니다!!");
			sc.nextLine();
		}
	}
	
	public void setLog(String s){
		
		log.add(s);
	}
	
	public void showLog(){
		
		if(log.size() >= 1){
		System.out.println("현재까지 기록된 로그");
		
		for(String a:log){
			System.out.println("["+ log.indexOf(a) + ". " + a + "]");
						}
		sc.nextLine();
		
		}else{
			System.out.println("저장된 로그가 없습니다");
			sc.nextLine();
		}
	}
	
	
}
