package at.grisa.justlang.generator;

import java.util.HashMap;
import at.grisa.justlang.symbol.Symbol;

public class DescriptorFactory {
	private static DescriptorFactory instance;
	private HashMap<Symbol, Descriptor> descriptors;

	private DescriptorFactory() {
		descriptors = new HashMap<Symbol, Descriptor>();
	}

	public static DescriptorFactory getInstance() {
		if (instance == null) {
			instance = new DescriptorFactory();
		}
		return instance;
	}

	public Descriptor createDescriptor(Symbol symbol, Descriptor.Kind kind) {
		Descriptor descriptor = new Descriptor(symbol, kind);
		descriptors.put(symbol, descriptor);
		System.out.println(descriptor);
		return descriptor;
	}
	
	public Descriptor getDescriptor(Symbol symbol) {
		return descriptors.get(symbol);
	}
}
