import java.util.Random;

class Animal
{
	public void sound()
	{
		System.out.println("I am an animal");
	}
}

class Dog extends Animal
{
	@Override
	public void sound()
	{
		System.out.println("I am a dog");
	}
}

class Cat extends Animal
{
	@Override
	public void sound()
	{
		System.out.println("I am a cat");
	}
}

class Rabbit extends Animal
{
	@Override
	public void sound()
	{
		System.out.println("I am a rabbit");
	}
}

class Donkey extends Animal
{
	@Override
	public void sound()
	{
		System.out.println("I am a Donkey");
	}
}

class Test
{
	public static void main(String args[])
	{
		Animal kingdom[] = new Animal[100];

		Random rand = new Random();
		int index = rand.nextInt(100);

		for(int i = 0; i < kingdom.length; i++)
		{
			index = rand.nextInt(100);
			if(index <= 25)
			{
				kingdom[i] = new Dog();
			}
			else if(index > 25 && index <= 50)
			{
				kingdom[i] = new Cat();
			}
			else if(index > 50 && index <= 75)
			{
				kingdom[i] = new Rabbit();
			}
			else
			{
				kingdom[i] = new Donkey();
			}
		}
		index = rand.nextInt(100);
		kingdom[index].sound();	
	}
}