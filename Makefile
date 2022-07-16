build:
	./flexipatch-finalizer.sh -r -d dwm-flexipatch -o dwm
	git checkout main
	rm -rf .config/dwm
	mv dwm .config/dwm
	git checkout .config/dwm/config.h