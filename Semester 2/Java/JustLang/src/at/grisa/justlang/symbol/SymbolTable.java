package at.grisa.justlang.symbol;

import java.util.LinkedList;

public class SymbolTable {
	private LinkedList<Symbol> symbols;

	public SymbolTable() {
		symbols = new LinkedList<Symbol>();
	}

	public void insert(Symbol symbol) {
		symbols.add(symbol);
		System.out.println("new symbol: " + symbol);
	}
	
	public LinkedList<Symbol> getSymbols(){
		return symbols;
	}
}
