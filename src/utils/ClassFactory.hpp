#pragma once
#include <string>
#include <map>
#include <functional>

class ClassFactory {
protected:
	typedef std::map<std::string, std::function<void*()>> FactoryMap;
	FactoryMap factory;

public:
	template <class Class>
	void add(const std::string & slug) {
		this->factory[slug] = [] { return new Class(); };
	}

	void* create(const std::string & slug) {
		auto it = this->factory.find(slug);
		if (it != this->factory.end())
			return it->second();

		return nullptr;
	}
};