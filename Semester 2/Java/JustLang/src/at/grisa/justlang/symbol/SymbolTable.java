package at.grisa.justlang.symbol;

import java.util.LinkedList;

public class SymbolTable {
	private LinkedList<Symbol> symbols;
	private int localIndexCounter;
	private int globalIndexCounter;
	
	public SymbolTable(int globalIndexCounterStart) {
		symbols = new LinkedList<Symbol>();
		this.globalIndexCounter = globalIndexCounterStart;
		this.localIndexCounter = 0;
	}

	public void insert(Symbol symbol) {
		switch(symbol.kind){
			case CONSTANT:
				symbol.index = this.globalIndexCounter++;
				break;
			case VARIABLE:
				symbol.index = this.localIndexCounter++;
				break;
		}
		
		symbols.add(symbol);
		System.out.println("new symbol: " + symbol);
	}
	
	public LinkedList<Symbol> getSymbols(){
		return symbols;
	}

	public int getGlobalIndexCounter() {
		return globalIndexCounter;
	}
}
