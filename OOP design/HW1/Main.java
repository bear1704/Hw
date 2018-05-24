package new_pos;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

//
// 20133222 박수찬
//

public class Main {

	
	Log log = new Log(); 
	Worker worker = new Worker(); 
	Sell sell = new Sell();
	Scanner sc = new Scanner(System.in);
	Cash cash = new Cash();
	ArrayList<Product> p = new ArrayList<>();
	Inventory iv = new Inventory();
	String input;
	
	public static void main(String[] args){
		
		Main main = new Main();
		main.init();
		main.welcome();
		
		
	}

	public void init(){  //설명 : 프로그램이 실행되면 가장 먼저 실행되는 메소드입니다. 만약 저장된 데이터가 있다면 객체들을 그 데이터에 맞춰 초기화시키고, 없으면 새로 만듭니다.
		File f = new File("save.sav");
		if(f.exists()){
			
			try{
				
			FileInputStream fis = new FileInputStream("save.sav");
			ObjectInputStream ois = new ObjectInputStream(fis);
			
			cash = (Cash) ois.readObject();
			p = (ArrayList<Product>) ois.readObject();
			log = (Log) ois.readObject();
			iv = (Inventory) ois.readObject();
			sell = (Sell) ois.readObject();
			worker = (Worker) ois.readObject();
			ois.close();
			}catch(Exception e){
				e.printStackTrace();
			}
			
			
		}
		
		
	}
	
	public void welcome(){  //설명 : 메인 화면에서 할 행동을 고를 수 있게 안내문을 띄우는 메소드입니다. 또한 작업을 마치면 다시 여기로 돌아오게 되므로,
							//     돌아올 때 마다 데이터를 저장해서 보관할 수 있게 합니다.
		
		//저장 과정
		
		try{
			FileOutputStream fos = new FileOutputStream("save.sav");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			
			oos.writeObject(cash);
			oos.writeObject(iv.getProduct());
			oos.writeObject(log);
			oos.writeObject(iv);

			oos.writeObject(sell);
			oos.writeObject(worker);
			oos.close();
			
		}catch(Exception e){}
		
		
		//-----------------
		System.out.println("-----------------------------------");
		System.out.println("              POS                  ");
		System.out.println("-----------------------------------");
		System.out.println("현재 근무자는 " + worker.getName() + " 입니다. \n");
		System.out.println("현재 잔고 :  " + cash.getCash());
		System.out.println("[판매] 물품 판매");
		System.out.println("[관리] 재고 관리");
		System.out.println("[교대] 근무자 교대");
		System.out.println("[로그] 관리자 기능");
		System.out.print("입력 : ");
		
		String str = sc.nextLine();
		
		switch(str){  
		case "교대":
			System.out.print("교대받을 이름을 입력해 주세요 : ");
			input = sc.nextLine();
			worker.setWorker(input,log);
			welcome();
			break;
		case "관리":
			iv.welcome(worker,log);
			welcome();
			break;
		case "판매":
			sell.welcome(iv.getProduct(),cash,log);
			welcome();
			break;
		case "로그": 
			log.welcome(worker);
			welcome();
			break;
			
		
		}
	    
	}
	
}

