require_relative("./imports.rb")
class Humans
    attr_accessor :number_of_humans
    def initialize(number_humans)
        @number_of_humans = number_humans
    end 
    def add_human(count = 1)
        @number_of_humans = @number_of_humans + count
    end
end

class Person < Humans
    attr_accessor :name, :age
    undef_method :add_human
    def initialize(name, age, number_humans)
        @name = name
        @age = age
        super(number_humans)
    end
end

total_humans = Humans.new(2)
puts total_humans.number_of_humans
total_humans.add_human(2)
puts total_humans.number_of_humans

person = Person.new("Jack",10,2)
puts person.name
puts person.age
puts person.number_of_humans

#person.add_human(10)
puts person.number_of_humans

pet = Pet.new("Petman",5,"Lion")
pet.walk()