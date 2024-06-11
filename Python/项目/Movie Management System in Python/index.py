movies = []
START = "\n=========== Movie Management System ===========\n\n\nEnter 1 to Add Movies, \nEnter 2 to Display Movies \nEnter 3 to Search a Movie by Title \nEnter 4 to Quit Application \n"


def add_movie():
    title = input("Enter title of the film: ")
    director = input("Enter director of the film: ")
    year = input("Enter year of the film: ")
    genre = input("Enter genre of the film: ")
    movies.append({
        'title': title,
        'year': year,
        'director': director,
        'genre': genre
    })


def list_movies():
    quantity = len(movies)
    titles = [movie['title'] for movie in movies]
    titles = '\n'.join(titles)

    if quantity:
        print(f'\nList of movies that have in your collection: \n{titles}. \nIn total you have {quantity} {"movie" if quantity == 1 else "movies"}.')
    else:
        print('There are no movies in your collection.')


def print_movie_info(movie):
    print('Here is information about requested title')
    print(f'Title: {movie["title"]},')
    print(f'Director: {movie["director"]},')
    print(f'Year: {movie["year"]},')
    print(f'Genre: {movie["genre"]}.')


def find_title():
    search_title = input('Enter title you are looking for: ')
    for movie in movies:
        if movie['title'] == search_title:
            print_movie_info(movie)
        else:
            print('Requested title was not found in the collection.')


user_selection = {
    '1': add_movie,
    '2': list_movies,
    '3': find_title
}


def menu():
    selection = input(START)
    while selection != '4':
        if selection in user_selection:
            selected_action = user_selection[selection]
            selected_action()
        else:
            print("Unknown command. Please choose within available options: 1, 2, 3 or 4 to close the app.")
        selection = input(START)
    print('Thank you for using the app. See you next time!')


if __name__ == '__main__':
    menu()
