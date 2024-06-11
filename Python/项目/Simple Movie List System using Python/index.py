movies = []
entry_start = "===========Simple Movie List System===========\n\nEnter the letter of the menu selection\n 'a' to add a movie, \n 'm' to see your movie list, \n 'f' to find a movie by title, \n or 'q' to quit: "


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
    titles = ', '.join(titles)

    if quantity:
        print(f'You have following movies in collection: {titles}. In total you have {quantity} {"movie" if quantity == 1 else "movies"}.')
    else:
        print('There are no movies in you collection.')


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
    'a': add_movie,
    'm': list_movies,
    'f': find_title
}


def menu():
    selection = input(entry_start).lower()
    while selection != 'q':
        if selection in user_selection:
            selected_action = user_selection[selection]
            selected_action()
        else:
            print("Unknown command. Please choose within available options: 'a', 'f', 'l' or 'q' to close the app.")
        selection = input(entry_start)
    print('Thank you and see you again!')


if __name__ == '__main__':
    menu()
