package at.grisa.justlang.symbol;

public class SymbolFactory {
	private static SymbolFactory instance;

	private SymbolFactory() {

	}

	public static SymbolFactory getInstance() {
		if (instance == null) {
			instance = new SymbolFactory();
		}
		return instance;
	}

	public Symbol createVariableSymbol(String name, Object value, Type type, int level) {
		Symbol symbol = new Symbol();
		symbol.type = type;
		symbol.value = value;
		symbol.name = name;
		symbol.level = level;

		return symbol;
	}
}
