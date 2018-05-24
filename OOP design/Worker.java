package new_pos;
//
//20133222 박수찬
//

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class Worker implements Serializable{ // 설명: 근무자는 바뀌지 않는다 가정했습니다. 각 근무자는 이름과, 관리자 권한만을 가진 간단한 객체입니다.
											//      관리자 권한은 로그 확인이나 물품 생성 등 특별한 행위에 필요합니다.
	
	public Worker(){
		
		name.put(0, "철수");
		name.put(1, "수민");
		name.put(2, "민수");
		name.put(3, "수철");
		name.put(4, "점장");
		
		worker = name.get(0);
		master = false;
	}
	
	 
	private String worker;
	HashMap<Integer,String> name = new HashMap<>();
	private boolean master;
	

	
	public String getName(){
		return worker;
	}
	public boolean getAdmin(){
		return master;
	}
	
	public String setWorker(String name,Log l){
		
		if(this.name.containsValue(name))
		{
			if(name.equals("점장")){
				System.out.println(name + " 으로 변경되었습니다");
				
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
				String date = sdf.format(cal.getTime());
				l.setLog(date + " " + "근무자가 " + worker + " 에서 " + name + " 으로 변경되었습니다.");
				master = true;
				worker = name;
				
				return name;
			}else{
				System.out.println(name + " 으로 변경되었습니다");
				
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
				String date = sdf.format(cal.getTime());
				l.setLog(date + " " + "근무자가 " + worker + " 에서 " + name + " 으로 변경되었습니다.");
				master = false;
				worker = name;
				return name;
			}
		
		}else{
			System.out.println("그런 근무자는 존재하지 않습니다");
			return worker; 
		}
	}

}
