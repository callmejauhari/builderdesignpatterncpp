#include <iostream>
#include <vector>

using namespace std;
class GuitarBuilder
{
protected:
    string wood;
    string tuner;
    string strings;

public:
    virtual void SetWood() = 0;
    virtual void SetTuner() = 0;
    virtual void SetStrings() = 0;
    void GetGuitar()
    {
        cout << "Wood:" << wood << " Tuner: " << tuner << " Strings: " << strings << endl;
    }
};

class ExpensiveGuitarBuilder : public GuitarBuilder
{
public:
    void SetWood() override
    {
        wood = "solid";
    }
    void SetTuner() override
    {
        tuner = "titanium";
    }
    void SetStrings() override
    {
        strings = "ernie ball";
    }
};

class CheapGuitarBuilder : public GuitarBuilder
{
public:
    void SetWood() override
    {
        wood = "laminated";
    }
    void SetTuner() override
    {
        tuner = "alumunium";
    }
    void SetStrings() override
    {
        strings = "pyramid";
    }
};

class GuitarDirector
{
    GuitarBuilder *builder;

public:
    GuitarBuilder *CreateFullGuitar(GuitarBuilder *builder)
    {
        this->builder = builder;
        this->builder->SetWood();
        this->builder->SetTuner();
        this->builder->SetStrings();
        return this->builder;
    }
    GuitarBuilder *CreateNonCompletedGuitar(GuitarBuilder *builder)
    {
        this->builder = builder;
        this->builder->SetWood();
        this->builder->SetTuner();
        return this->builder;
    }
    void GetGuitar()
    {
        this->builder->GetGuitar();
    }
};


int main()
{
    GuitarDirector director;
    GuitarBuilder *builder = new ExpensiveGuitarBuilder;
    builder = director.CreateFullGuitar(builder);
    builder->GetGuitar();
    builder = director.CreateNonCompletedGuitar(new CheapGuitarBuilder);
    builder->GetGuitar();
}