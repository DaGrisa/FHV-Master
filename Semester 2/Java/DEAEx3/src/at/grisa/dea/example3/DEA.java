package at.grisa.dea.example3;

public class DEA {
	public static void main(String args[]){
		System.out.println(DEA.accept("zxz".toCharArray()));
		System.out.println(DEA.accept("xyz".toCharArray()));
		System.out.println(DEA.accept("zxyz".toCharArray()));
		System.out.println(DEA.accept("zzzzxyz".toCharArray()));
		System.out.println(DEA.accept("zzxz".toCharArray()));
		
		System.out.println(DEA.accept("azxz".toCharArray()));
		System.out.println(DEA.accept("xyza".toCharArray()));
		System.out.println(DEA.accept("z xyz".toCharArray()));
		System.out.println(DEA.accept("zzyzzxyz".toCharArray()));
		System.out.println(DEA.accept("zzz".toCharArray()));
	}
	
	public static boolean accept(char[] tape){
		String state = "A";
		
		for(char symbol : tape){
			switch(state){
			case "A":
				if(symbol=='z'){
					state = "A";
				} else if (symbol == 'x'){
					state = "B";
				} else {
					return false;
				}
				break;
			case "B":
				if(symbol =='z'){
					state = "C";
				} else if(symbol == 'y'){
					state = "D";
				} else {
					return false;
				}
				break;
			case "C":
				return false;
			case "D":
				if(symbol == 'z'){
					state = "C";
				} else {
					return false;
				}
				break;
			}
		}
		if(state=="C") return true;
		return false;
	}
}
