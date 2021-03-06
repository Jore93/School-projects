#include "priceInfoContainer.h"
#include <iostream>

int main() {
	PriceInfoContainer container;
	std::vector<PriceInfo*> vec;
	int index = 1;
	while(true) {
		container.lisaaHintatieto();
		index++;
		while(index > 5) {
			std::string vast;
			std::cout << "Haluatko lopettaa? (y/n): " << std::endl;
			std::cin >> vast;
			if(vast == "y") {
				container.tulostaSailio();
				double raja = container.kysyHinta();
				std::cout << std::endl;
				container.tulostaSopivat(raja);
				std::cout << std::endl;
				container.tulostaLiianKalliit(raja);
				vec = container.getHintatietoVektori();
				for(unsigned i=0; i<vec.size(); i++) {
					Vehicle* tmp = vec[i]->getVehicle();
					delete(tmp);
					delete(vec[i]);
				}
				std::cout << "Kiitos käytöstä!" << std::endl;
				return 0;
			}
			else if(vast == "n") {
				break;
			}
			else {
				std::cout << "Syötä 'y', jos haluat lopettaa ja 'n', jos haluat jatkaa" << std::endl;
			}
		}
	}
	return 1;
}

