class Pet
    attr_accessor :name, :age, :species
    def initialize(name, age, species)
        @name = name
        @age = age
        @species = species
      end 
    def walk()
        puts "#{species} is walking..."
    end
end

#pet = Pet.new("Jacky",10,"Cat")
#pet.walk()