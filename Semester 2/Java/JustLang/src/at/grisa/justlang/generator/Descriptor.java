package at.grisa.justlang.generator;

import at.grisa.justlang.symbol.Symbol;

public class Descriptor {
	public enum Kind {
		CONSTANT, LOCAL, STACK
	}
	
	public Symbol symbol;
	public Descriptor.Kind kind;

	public Descriptor(Symbol symbol, Kind kind) {
		this.symbol = symbol;
		this.kind = kind;
	}

	@Override
	public String toString() {
		return "Descriptor [symbol=" + symbol + ", kind=" + kind + "]";
	}
	
}
