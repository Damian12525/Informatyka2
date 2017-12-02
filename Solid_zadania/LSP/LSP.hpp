#ifndef SHAPES_HPP_
#define SHAPES_HPP_

class Quadrilateral {
	public:
		virtual double Area() const = 0;
};

class Rectangle : public Quadrilateral {
	private:
		double _width;
		double _height;
		
	public:
		void setWidth(double w) { _width = w; }
		void setHeight(double h) { _height = h; }
		double getHeight() const { return _height; }
		double getWidth() const { return _width; }

		virtual double Area() const override { return _height*_width; }
};

class Square : public Quadrilateral {
	private:
		double _side;

	public:
		void setSide(double s) { _side = s; }
		double getSide() const { return _side; }
		virtual double Area() const override { return _side*_side; }
};

#endif
