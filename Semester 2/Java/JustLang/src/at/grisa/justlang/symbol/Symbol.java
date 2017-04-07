package at.grisa.justlang.symbol;

public class Symbol {
	public enum Kind {
		UNDEFINED, CONSTANT, VARIABLE, PARAMETER, FUNCTION
	};

	public String name;
	public Kind kind;
	public Type type; // data type
	public boolean isInitialized; // is init? for vars only
	public Object value; // for constants and initialized vars only 
	public int address; //for globals, params, consts and local vars
	
	// for functions only
	public boolean isDefined; // is func already defined
	//public Symbol symbols; // params and loc vars
	public int level; // scope level
	
	@Override
	public String toString() {
		return "Symbol [name=" + name + ", kind=" + kind + ", type=" + type + ", isInitialized=" + isInitialized
				+ ", value=" + value + ", address=" + address + ", isDefined=" + isDefined + ", level=" + level + "]";
	}
}