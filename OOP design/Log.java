package new_pos;


//
//20133222 �ڼ���
//�������� Log ����� ����մϴ�

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;
public class Log implements Serializable{

	ArrayList<String> log = new ArrayList<>();
	static Scanner sc = new Scanner(System.in);
	
	
	public void welcome(Worker w){
		System.out.println("---------�α� ���� ����Դϴ�.-----");
		
		if(w.getAdmin()){
		showLog();}
		else{
			System.out.println("������ �����ϴ�!!");
			sc.nextLine();
		}
	}
	
	public void setLog(String s){
		
		log.add(s);
	}
	
	public void showLog(){
		
		if(log.size() >= 1){
		System.out.println("������� ��ϵ� �α�");
		
		for(String a:log){
			System.out.println("["+ log.indexOf(a) + ". " + a + "]");
						}
		sc.nextLine();
		
		}else{
			System.out.println("����� �αװ� �����ϴ�");
			sc.nextLine();
		}
	}
	
	
}
