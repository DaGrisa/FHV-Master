package at.grisa.justlang.scope;

import java.util.Arrays;

import at.grisa.justlang.symbol.Symbol;
import at.grisa.justlang.symbol.SymbolTable;

public class Scope {
	public SymbolTable localSymbols;
	public Scope outerScope;
	public int level;

	public Scope(int level) {
		localSymbols = new SymbolTable();
		this.level = level;
		System.out.println("new scope: Scope level " + this.level);
	}

	@Override
	public String toString() {
		StringBuilder output = new StringBuilder("Scope level " + level);

		char[] repeat = new char[3 * level];
		Arrays.fill(repeat, ' ');
		String spaces = new String(repeat);

		for (Symbol symbol : localSymbols.getSymbols()) {
			output.append("\n" + spaces + symbol);
		}

		return output.toString();
	}
}
