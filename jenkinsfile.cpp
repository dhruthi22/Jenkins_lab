pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    // Assuming your .cpp file is named "your_file.cpp"
                    def cppFileName = 'hello.cpp'
                    
                    echo "Compiling ${cppFileName}..."
                    sh "g++ -o ${cppFileName.replace('.cpp', '')} ${cppFileName}"
                    
                    // Build YOUR_SRN-1
                    def yourSRN = "YOUR_SRN-${BUILD_NUMBER - 1}"
                    echo "Building ${yourSRN}..."
                    // Add additional build commands if necessary
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    // Assuming your compiled executable has the same name as your .cpp file
                    def executable = 'your_file'
                    
                    echo "Running tests..."
                    sh "./${executable}"
                }
            }
        }

        stage('Deploy') {
            steps {
                script {
                    echo 'Deploying the application...'
                    // Add commands or scripts for deploying your application
                }
            }
        }
    }

    post {
        always {
            echo 'Post-condition: Display "pipeline failed" in case of any errors.'
        }

        failure {
            echo 'Pipeline failed!'
            // You can add additional actions to be performed in case of failure
            // For example, sending notifications, cleaning up resources, etc.
        }
    }
}
